#include<bits/stdc++.h>
#define int long long
using namespace std;

struct club{
	int interest;
	int name;
};
struct person{
	club clubs[5];
	int pick=0, id;
	void init() {
		pick=0;
		sort(clubs,clubs+3,
			[](club a, club b){
				return a.interest>b.interest;
			}
		);
	}
	club get() {
		return clubs[pick];
	}
	void disable() {
		pick++;
	}
};
struct joint{
	int id;
	int interest;
};
struct cmp{
	bool operator()(joint a, joint b){
		return a.interest>b.interest;
	}
};

constexpr int maxn=1e5+5;

priority_queue<joint, vector<joint>, cmp> heaps[3];
person people[maxn];

int T, n;

void make(person p){
	club current=p.get();
	int id=p.id;
	if(heaps[current.name].size()<n/2)
		heaps[current.name].push({id, current.interest});
	else{
		joint jnt=heaps[current.name].top();
		joint to={id, current.interest};
		
		int x=-jnt.interest+to.interest+people[jnt.id].clubs[people[jnt.id].pick+1].interest;
		int y=p.clubs[p.pick+1].interest;
		if(x<y) {
			people[id].disable();
			make(people[id]);
		} 
		else if(x==y) {
			if(people[jnt.id].clubs[people[jnt.id].pick+1].interest<y) {
				heaps[current.name].pop();
				heaps[current.name].push(to);
				people[jnt.id].disable();
				make(people[jnt.id]);
			} else {
				people[id].disable();
				make(people[id]);
			}
		}
		else {
			heaps[current.name].pop();
			heaps[current.name].push(to);
			people[jnt.id].disable();
			make(people[jnt.id]);
		}
	}
}

signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--) {
		// Init
		for(int i=0;i<3;i++) {
			while(!heaps[i].empty()) heaps[i].pop();
		}
		
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) {
			int a, b, c;
			scanf("%lld%lld%lld",&a,&b,&c);
			people[i].clubs[0].interest=a, people[i].clubs[0].name=0;
			people[i].clubs[1].interest=b, people[i].clubs[1].name=1;
			people[i].clubs[2].interest=c, people[i].clubs[2].name=2;
			people[i].id=i;
			people[i].init();
		}
		
		for(int i=1;i<=n;i++) {
			make(people[i]);
		}
		int sum=0;
		for(int i=0;i<3;i++) {
			while(!heaps[i].empty()) sum+=heaps[i].top().interest, heaps[i].pop();
		}
		printf("%lld\n",sum);
	}
	return 0;
}

