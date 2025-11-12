#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k;
int ans,c[15],a[10005][10005],fa[10005];
pair<ll,pair<ll,ll> > rd[2000005];
ll fi(int x){
//	cout<<x<<" "<<fa[x]<<endl;
	return fa[x]==x?fa[x]:fa[x]=fi(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		rd[i].first=w;
		rd[i].second.first=u;
		rd[i].second.second=v;
	}
	int cnt=m;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1,w;j<=n;j++){
			cin>>w;
			if(c[i]==0){
				cnt++;
				rd[cnt].first=w;
				rd[cnt].second.first=c[i];
				rd[cnt].second.second=j;
			}
		}
	}
	sort(rd+1,rd+cnt);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		ll u=rd[i].second.first,v=rd[i].second.second,w=rd[i].first;
		ll x=fi(u),y=fi(v);
		if(x==y)continue;
		ans+=w;
		fa[x]=y;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
