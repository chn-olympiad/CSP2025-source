#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e4+15;
struct node{
	ll l,r,w;
	bool operator <(const node &a)const{
		return w>=a.w;
	}
};
ll n,m,k,fa[N],gg[N],tt[15][N],vis[N],minx[N],tu[N];
ll find(ll k){
	return fa[k]==k?k:fa[k]=find(fa[k]);
}
ll js;
priority_queue<node>q,eq;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		ll x,y,z;cin>>x>>y>>z;
		q.push({x,y,z});
	}
	for(ll i=1;i<=k;i++)
	{
		ll x;cin>>x;tu[i+n]=x;
		minx[i+n]=1;
		for(ll j=1;j<=n;j++)
		{
			ll y;cin>>y;
			if(tt[i][minx[i+n]]>y)minx[i+n]=j;
			tt[i][j]=y;fa[j]=j;gg[j]=1;
		}
		q.push({i+n,minx[i+n],tt[i][minx[i+n]]+x});
		fa[i+n]=i+n;
	}
	while(!q.empty())
	{
//		cout<<q.top().l<<' '<<q.top().r<<' '<<q.top().w<<'\n';
//		cout<<js<<'\n';
		ll tx=find(q.top().l),ty=find(q.top().r);
		if(tx==ty){q.pop();continue;}
		if(q.top().l<=n)eq.push({q.top().l,q.top().r,q.top().w});
		vis[q.top().l]++;vis[q.top().r]++;
		ll l=q.top().l,t=q.top().w;q.pop();
		if(vis[l]==1&&l>n){
			minx[l]=t;
//			cout<<t<<' '<<minx[l]<<'\n';
			for(ll i=1;i<=n;i++){
				q.push({l,i,tt[l-n][i]+minx[l]});
//				cout<<tt[l-n][i]<<'\n';
			}
		}
		if(vis[l]==2&&l>n){
			js+=tu[l];
			for(ll i=1;i<=n;i++){
				eq.push({l,i,tt[l-n][i]});
//				cout<<l-n<<' '<<i<<' '<<tt[l-n][i]<<'\n';
			}
		}
		fa[tx]=ty;
		gg[ty]+=gg[tx];
		if(gg[ty]==n){
			break;
		}
	}
//	cout<<'\n';
	for(int i=1;i<=n+k;i++)fa[i]=i,gg[i]=(i<=n?1:0);
	while(!eq.empty())
	{
		ll tx=find(eq.top().l),ty=find(eq.top().r),t=eq.top().w;
//		cout<<eq.top().l<<' '<<eq.top().r<<' '<<eq.top().w<<'\n';
		eq.pop();
		if(tx==ty)continue;
		js+=t;
		fa[tx]=ty;
		gg[ty]+=gg[tx];
		if(gg[ty]==n)break;
	}
	cout<<js<<'\n';
	return 0;
}
/*
5 4 1
1 2 4
1 3 9
2 4 4
4 5 4
4 3 5 3 4 6
*/