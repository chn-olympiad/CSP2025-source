#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+10,M=5e4+10;
ll n,t,c;
struct node{
	ll a,b;
}a[N];
bool cmp(node x,node y){
	return x.a-x.b>y.a-y.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(ll i=1;i<=n;i++) cin>>a[i].a>>a[i].b>>c;
		sort(a+1,a+n+1,cmp);
		ll n2=n/2,ans=0;
		for(ll i=1;i<=n2;i++) ans+=a[i].a;
		for(ll i=n2+1;i<=n;i++) ans+=a[i].b;
		cout<<ans<<'\n';
//		for(ll i=1;i<=n;i++){
//			cout<<a[i].a<<' '<<a[i].b<<' '<<a[i].c<<'\n';
//		}
//		cout<<'\n';
//		ll f[N]={0},g[N]={0};
//		for(ll i=1;i<=n;i++){
//			ll lim=max(i-n2,1LL);
//			g+=max(a[i].c,a[i].a);
//			if(i>n2) g=max(g,f[n2]+a[i].c);
//			else f[i]=f[i-1]+a[i].b;
//			for(ll j=min(i-1,n2);j>=lim;j--){
//				f[j]=max(f[j-1]+a[i].b,f[j]+a[i].a);
//				g[j]=max(g[j]+a[i].a,g[j-1]+a[i].c);
//			}
//			if(i<=n2) f[0]+=a[i].a;
//			for(ll i=0;i<=n2;i++) cout<<f[i]<<' ';
//			cout<<g<<'\n';
//		}
//		cout<<max(f[n2],g)<<'\n';
	}
	return 0;
}
