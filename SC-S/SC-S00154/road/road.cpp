#include<bits/stdc++.h>
using namespace std;
#define i32 int
#define i64 long long
#define u32 unsigned int
#define u64 unsigned i64
#define Vec vector
struct edge{
	i64 u,v,w;
	bool operator<(edge e)const{
		return w<e.w;
	}
	bool operator>(edge e)const{
		return w>e.w;
	}
	bool operator<=(edge e)const{
		return w<=e.w;
	}
	bool operator>=(edge e)const{
		return w>=e.w;
	}
};
priority_queue<edge,Vec<edge>,greater<edge> > eq;
i64 n,m,k;
i64 c[17];
i64 a[10517][17];
i64 fa[10517];
i64 gf(i64 x){
	return ((x==fa[x])?x:(fa[x]=gf(fa[x])));
}
void mf(i64 x,i64 y){
	fa[gf(x)]=gf(y);
}
bool cf(i64 x,i64 y){
	return gf(x)==gf(y);
}
i32 main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(i64 i=0;i<=n;i++){
		fa[i]=i;
	}
	for(i64 _ed=0;_ed<m;_ed++){
		i64 u,v,w;
		cin>>u>>v>>w;
		eq.push(edge{u,v,w});
	}
	for(i64 tn=0;tn<k;tn++){
		cin>>c[tn];
		for(i64 v=1;v<=n;v++){
			cin>>a[tn][v];
		}
	}
	if(n>=1517){
		const i64 offset=10517;
		i64 ans=0x7fffffffffffffffll;
		i64 tec=n;
		if(k==0){
			for(i64 i=0;i<=n;i++)fa[i]=i;
			ans=0;
			i64 edgs=0;
			while((!eq.empty())&&edgs<tec-1){
				edge te=eq.top();
				eq.pop();
				if(!cf(te.u,te.v)){
					ans+=te.w;
					edgs++;
					mf(te.u,te.v);
				}
			}
			cout<<ans;
			return 0;
		}
		for(i64 ish=0;ish<(2<<(k-1));ish++){
			for(i64 i=0;i<=n;i++)fa[i]=i;
			for(i64 i=0;i<=k;i++)fa[i+offset]=i+offset;
			i64 tans=0;
			i64 mai=1;
			tec=n;
			priority_queue<edge,Vec<edge>,greater<edge> > neq(eq);
			for(i64 tn=0;tn<k;tn++,mai<<=1){
				if(ish&mai){
					tec++;
					tans+=c[tn];
					for(i64 v=1;v<=n;v++){
						neq.push(edge{
							tn+offset,
							v,
							a[tn][v]
						});
					}
				}
			}
			i64 edgs=0;
			while((!neq.empty())&&edgs<tec-1){
				edge te=neq.top();
				neq.pop();
				if(!cf(te.u,te.v)){
					tans+=te.w;
					edgs++;
					mf(te.u,te.v);
				}
			}
			if(edgs<tec-1){
				tans=0x7fffffffffffffffll;
			}
			ans=min(ans,tans);
		}
		cout<<ans;
		return 0;
	}
	for(i64 u=1;u<n;u++){
		for(i64 v=u+1;v<=n;v++){
			i64 mw=0x7ffffffffffffffll;
			for(i64 tn=0;tn<k;tn++){
				mw=min(mw,a[tn][u]+c[tn]+a[tn][v]);
			}
			eq.push(edge{u,v,mw});
		}
	}
	i64 edgs=0;
	i64 ans=0;
	while(edgs<n-1&&(!eq.empty())){
		edge te=eq.top();
		eq.pop();
		if(!cf(te.u,te.v)){
			ans+=te.w;
			edgs++;
			mf(te.u,te.v);
		}
	}
	cout<<ans;
	return 0;
}