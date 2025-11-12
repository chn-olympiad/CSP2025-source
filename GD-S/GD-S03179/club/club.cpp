#include<bits/stdc++.h>
using namespace std;
//#define int long long
void file(string fi){
	freopen((fi+".in").data(),"r",stdin);
	freopen((fi+".out").data(),"w",stdout);
} 
const int maxn=1e5+10;
struct prio{
	multiset<pair<int,int> ,greater<pair<int,int> > >x;
	void push(pair<int,int>  t){
		x.insert(t);
	}
	void pop(){
		x.erase(x.begin());
	}
	pair<int,int> top(){
		return *x.begin();
	} 
	int size(){
		return x.size();
	}
}qs[9];
int st[maxn];
vector<array<int,3> >a;
int fr[9]={4,4,4,0,1,2,1,2,0};
int to[9]={0,1,2,1,2,0,0,1,2};
vector<int> ca[9]={{3,8},{4,6},{5,7},{4,6},{5,7},{3,8},{3},{4},{5}};
void pu(int i,int s){
	int e=0,d=0;
	if(s<3)e=0;
	else e=a[i][fr[s]];
	d=a[i][to[s]];
	qs[s].push({d-e,i});
}
vector<vector<int> >ops={
	{0},{1},{2},{0,3},{1,4},{2,5},{0,3,4},{1,4,5},{2,3,5},
	{0,8},{1,6},{2,7},{0,8,7},{1,6,8},{2,7,6}
};
signed main(){
	file("club");
	int _;scanf("%d",&_);
	while(_--){
		for(int i=0;i<9;++i)while(qs[i].size())qs[i].pop();
		memset(st,0,sizeof st);
		int n;scanf("%d",&n);
		a.clear();
		a.resize(n);
		for(int i=0;i<n;++i)
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		int sum=0;
		for(int i=0;i<n;++i){
			st[i]=4;
			pu(i,0);
			pu(i,1);
			pu(i,2);
		}
		int m=n/2;
		int c[5]={0,0,0,0,0};
		for(int i=0;i<n;++i){
			for(int i=0;i<9;++i)
				while(qs[i].size()&&st[qs[i].top().second]!=fr[i])
					qs[i].pop();
			int mx=INT_MIN,mop=-1;
			for(int i=0;i<ops.size();++i){
				int rt=0;
				int ct[5]={0,0,0,0,0};
				bool ok=1;
				for(int j=0;j<ops[i].size();++j){
					if(qs[ops[i][j]].size()==0){
						ok=0;
						break;
					}
					rt+=qs[ops[i][j]].top().first;
					ct[to[ops[i][j]]]++;
					ct[fr[ops[i][j]]]--;
				}
				if(!ok)continue;
				for(int i=0;i<3;++i)
					if(ct[i]+c[i]>m)ok=0;
				if(ok&&rt>mx)mx=rt,mop=i;
			}
			sum+=mx;
			for(int i=0;i<ops[mop].size();++i){
				int id=qs[ops[mop][i]].top().second;
				for(int j=0;j<ca[ops[mop][i]].size();++j)
					pu(id,ca[ops[mop][i]][j]);
				qs[ops[mop][i]].pop();
				st[id]=to[ops[mop][i]];
				c[to[ops[mop][i]]]++;
				c[fr[ops[mop][i]]]--;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
