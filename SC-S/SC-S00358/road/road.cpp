#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e6+5;
ll n,m,k;
struct node{
	ll x,y,z;
	friend bool operator<(node t1,node t2){
		return t1.z<t2.z;
	}
}e[N],p[N];
ll o=0;
ll fa[N];
ll find(ll x){return x==fa[x]?x:fa[x]=find(fa[x]);}
ll a[15][10005],val[15];
ll ans=0x3f3f3f3f3f3f3f3f;
ll getans(ll S){
	memcpy(p,e,sizeof(p));
	ll q=o,res=0,cnt=n;
	for(ll i=1;i<=k;i++){
		if(!(S&(1<<(i-1))))continue;
		res+=val[i];
		cnt++;
		for(ll j=1;j<=n;j++)p[++q]={i+n,j,a[i][j]};
	}
	sort(p+1,p+1+q);
	for(ll i=1;i<=n+k;i++)fa[i]=i;
	int js=0;
	for(ll i=1;i<=q;i++){
		ll f1=find(p[i].x),f2=find(p[i].y);
		if(f1!=f2){
			js++;
			fa[f1]=f2;res+=p[i].z;
			if(res>=ans)return 0x3f3f3f3f3f3f3f3f;
			if(js>=cnt-1)break;
		}
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		ll x,y,z;cin>>x>>y>>z;
		e[++o]={x,y,z};
	}
	for(ll i=1;i<=k;i++){
		cin>>val[i];
		for(ll j=1;j<=n;j++)cin>>a[i][j];
	}
	for(ll i=0;i<(1<<k);i++)ans=min(ans,getans(i));
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/