#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n;
struct st{
	ll x,y,z,d;
}a[100005];
bool cmp1(st a,st b){
	return a.x>b.x;
}
bool cmp2(st a,st b){
	return a.y>b.y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
			a[i].d=i;
		}
		ll ans=0;
		vector<ll> xx,yy,zz,k(n+5,0);
		xx.clear(),yy.clear(),zz.clear();
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++){
			if(xx.size()==n/2)break;
			if(k[a[i].d])continue;
			ll ma=max({a[i].x,a[i].y,a[i].z});
			if(ma==a[i].x)xx.push_back(a[i].x),k[a[i].d]=1;
		}
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++){
			if(yy.size()==n/2)break;
			if(k[a[i].d])continue;
			ll ma=max({a[i].x,a[i].y,a[i].z});
			if(ma==a[i].y)yy.push_back(a[i].y),k[a[i].d]=1;
		}
		for(int i=1;i<=n;i++){
			if(k[a[i].d])continue;
			zz.push_back(a[i].z);
		}
		for(int i=0;i<xx.size();i++)ans+=xx[i];
		for(int i=0;i<yy.size();i++)ans+=yy[i];
		for(int i=0;i<zz.size();i++)ans+=zz[i];
		printf("%lld\n",ans);
	}
	return 0;
}
