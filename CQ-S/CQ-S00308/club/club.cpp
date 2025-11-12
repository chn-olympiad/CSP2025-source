#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,m,ma,mb,mc;
struct ox{ll a,b,c,x;};
ox zxy[100010],p[100010];
ll uif(ll x){
	ll a=zxy[x].a,b=zxy[x].b,c=zxy[x].c;
	if(ma>mb&&ma>mc&&a>=b&&a>=c) return 1;
	if(mb>ma&&mb>mc&&b>=a&&b>=c) return 1;
	if(mc>ma&&mc>mb&&c>=a&&c>=b) return 1;
	return 0;
}
ll cmp_min(ox a,ox b) {return a.x<b.x;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	cin>>t;
	while(t--){
		ll z=0;
		cin>>n;
		m=ma=mb=mc=0;
		for(ll i=1;i<=n;i++){
			ll a,b,c;cin>>a>>b>>c;
			zxy[i].a=a;zxy[i].b=b;zxy[i].c=c;
			if(a>=b&&a>=c) ma++;
			else if(b>=a&&b>=c) mb++;
			else if(c>=a&&c>=b) mc++;
			z=z+max(a,max(b,c));
			
			if(a<b) swap(a,b);
			if(a<c) swap(a,c);
			if(b<c) swap(b,c);
			zxy[i].x=a-b;
		}
		if(max(ma,max(mb,mc))<=n/2) {
			cout<<z<<"\n";continue;
		}
		
		for(ll i=1;i<=n;i++){
			if(uif(i)==1) p[++m]=zxy[i];
		}
		std::sort(p+1,p+m+1,cmp_min);
		ll uq=m-n/2;
		for(ll i=1;i<=uq;i++) z=z-p[i].x;
		cout<<z<<"\n"; 
	}
	return 0;
}
/*
考虑贪心

先全部选择最大值

然后注意到不超过n/2的性质

只要把超过n/2的那些人分去别的地方即可

记换组的代价一定是最大值减去次大值，然后排序减了即可 
*/

