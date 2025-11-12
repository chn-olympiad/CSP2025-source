#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;
ll fa[10010];
ll find(ll x){
	if(fa[x]!=x)
		fa[x]=find(fa[x]);
	return fa[x];
}
struct edge{
	int st,ed,val;
}e[1000010];
ll a[15][10010],c[15];
bool cmp(edge e1,edge e2){
	return e1.val<e2.val;
}
ll sum,ans;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
		cin>>e[i].st>>e[i].ed>>e[i].val;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m&&sum<n-1;i++){
		int g1=find(e[i].st);
		int g2=find(e[i].ed);
		if(g1!=g2){
			sum++;
			ans+=e[i].val;
			fa[g1]=g2;
		}
	}
	cout<<ans;
	return 0;
}

