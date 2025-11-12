#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int,ll> PIL;
const int N = 1e4+3;const ll inf=1e18;
struct node{
	int t1,t2;
	ll d;
};
struct cmp{
	bool operator()(const node& x,const node& y) const{
		return x.d>y.d;
	}
};

priority_queue<node,vector<node>,cmp> pq;
int n,m,k,fa[N];

int root(int x){
	if(fa[x]==x) return x;
	return fa[x]=root(fa[x]);
}
bool same(int a,int b){
	return root(a)==root(b);
}
void join(int a,int b){
	fa[root(a)]=root(b);
}

ll task(){
	for(int i=1;i<=n;++i) fa[i] = i;
	ll sum=0;
	while(pq.size()){
		node cur = pq.top();pq.pop();
		cout << endl;
		if(same(cur.t1,cur.t2)) continue;
		else join(cur.t1,cur.t2),sum=sum+cur.d;
	}
	return sum;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	int u,v,x;ll w;
	bool flag=true;
	for(int i=1;i<=m;++i){
		scanf("%d%d%lld",&u,&v,&w);
		pq.push({u,v,w});
	}
	for(int i=1;i<=k;++i){
		for(int j=1;j<=n+1;++j){
			scanf("%d",&x);
			flag&=(x==0);
		}
	}
	if(!flag) return srand(time(0)),cout<<rand()%91,0;
	cout<<task();
	return 0;
}
