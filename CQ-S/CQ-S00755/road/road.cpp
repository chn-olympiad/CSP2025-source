#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k;
struct node{
	ll x,y,w;
}l[2000005];
ll c[15];
bool cmp(node a,node b){
	return a.w+(a.x>n?c[a.x-n]:0LL)<b.w+(b.x>n?c[b.x-n]:0LL);
}
ll a[15][20005];
ll p[20005];
ll find(ll x){
	if(p[x]==x)return x;
	return p[x]=find(p[x]);
}
bitset<20005>v;
ll ad[20005];
ll ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=n+k;i++)p[i]=i;
	for(ll i=n+1;i<=n+k;i++)ad[i]=1;
	for(ll i=1;i<=m;i++)cin>>l[i].x>>l[i].y>>l[i].w;
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++)cin>>a[i][j];
	}
	for(ll i=1;i<=k;i++){
		for(ll j=1;j<=n;j++){
			m++;
			l[m].x=i+n;
			l[m].y=j;
			l[m].w=a[i][j];
		}
	}
	sort(l+1,l+1+m,cmp);
	for(ll i=1;i<=m;i++){
		ll f1=find(l[i].x),f2=find(l[i].y);
		if(f1==f2)continue;
		p[f1]=f2;
		ans+=l[i].w;
		if(l[i].x>n&&ad[l[i].x])ans+=c[l[i].x-n],ad[l[i].x]=0;
//		cout<<l[i].x<<" "<<l[i].y<<" "<<l[i].w<<"\n";
		if(1<=l[i].x&&l[i].x<=n)v[l[i].x]=1;
		if(1<=l[i].y&&l[i].y<=n)v[l[i].y]=1;
		if(v.count()==n)break;
	}
	cout<<ans;
	return 0;
}

/*
бл~ю╤ 
*/

