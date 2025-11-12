#include<bits/stdc++.h>
using namespace std;
struct node{
	int fr,ed;
	long long weigh;
	friend bool operator < (node x,node y){
		return x.weigh<y.weigh;
	}
}ask[1000100],eg[10100],ad[100100];
struct dsu{
	int fa[10100],rk[10100];
	int find(int x){
		if(fa[x]^x){
			fa[x]=find(fa[x]);
		}
		return fa[x];
	}
	inline void merge(int x,int y){
		x=find(x);
		y=find(y);
		if(rk[y]<rk[x])
		swap(x,y);
		fa[x]=fa[y];
		rk[y]=max(rk[x]+1,rk[y]);
	}
}ds;
int n,m,q,ecnt,head[10100];
long long c[20],ans=0x3f3f3f3f;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;++i){
		scanf("%d%d%lld",&ask[i].fr,&ask[i].ed,&ask[i].weigh);
	}
	long long ta;
	for(int i=1;i<=q;++i){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;++j){
			scanf("%lld",&ta);
			++ecnt;
			ad[ecnt]=node{n+i,j,ta};
		}
	}
	sort(ask+1,ask+m+1);
	sort(ad+1,ad+ecnt+1);
	// for(int i=1;i<=ecnt;++i){
	// 	cout<<ad[i].fr<<" "<<ad[i].ed<<"  "<<ad[i].weigh<<endl;
	// }
	for(int i=1;i<=n;++i){
		ds.fa[i]=i;
	}
	long long rtr=0;
	int tcnt=0;
	for(int i=1;i<=m;++i){
		if(ds.find(ask[i].fr)^ds.find(ask[i].ed)){
			rtr+=ask[i].weigh;
			ds.merge(ask[i].fr,ask[i].ed);
			++tcnt;
			eg[tcnt]=ask[i];
			// cout<<eg[tcnt].fr<<" "<<eg[tcnt].ed<<"  "<<eg[tcnt].weigh<<endl;
		}
	}
	ans=rtr;
	auto check=[&](node x,int y){
		if(x.fr<=n||(y&(1<<(x.fr-n-1)))){
			if(ds.find(x.fr)^ds.find(x.ed)){
				rtr+=x.weigh;
				ds.merge(x.fr,x.ed);
			}
		}
	};
	for(int j=1;j<(1<<q);++j){
		rtr=0;
		for(int i=1;i<=q;++i){
			if((j>>(i-1))&1)
			rtr+=c[i];
		}
		int ccnt=0;
		for(int i=1;i<=n+q;++i){
			ds.fa[i]=i;
		}
		memset(ds.rk,0,sizeof(ds.rk));
		int pa=1,pb=1;
		for(;pa<=tcnt&&pb<=ecnt;){
			if(eg[pa]<ad[pb]){
				check(eg[pa],j);
				++pa;
			}else{
				check(ad[pb],j);
				++pb;
			}
		}
		for(;pa<=tcnt;++pa){
			check(eg[pa],j);
		}
		for(;pb<=tcnt;++pb){
			check(ad[pb],j);
		}
		ans=min(ans,rtr);
	}
	printf("%lld\n",ans);
	return 0;
}