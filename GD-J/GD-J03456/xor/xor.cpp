#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn=5e5+5;

struct g{
	ll x,y;
}p[maxn];

ll n,k,l,a[maxn],b[maxn];

bool cmp(g xx,g yy){
	return xx.y<yy.y;
}

int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k>>a[1];
	b[1]=a[1];
	for(ll i=2;i<=n;i++) {scanf("%lld",&a[i]);b[i]=b[i-1]^a[i];}
	
	ll ans=1;
	if(b[1]==k) p[++l].x==1,p[l].y=1;
	for(ll i=1;i<=n;i++){
		
		if(i==1){
			for(ll j=2;j<=n;j++){
				if(b[j]==k) p[++l].x=1,p[l].y=j;
			}
			continue;
		}
		for(ll j=i;j<=n;j++){
			ll d=b[j]^b[i-1];
			if(d==k) {p[++l].x=i,p[l].y=j;}
		}	
	}
	
	sort(p+1,p+l+1,cmp);
	
	ll ri=p[1].y;
	for(ll i=1;i<=l;i++){
		//cout<<p[i].x<<" "<<p[i].y<<endl;
		if(p[i].x>ri) ri=p[i].y,ans++;
	}
	
	cout<<ans;
	
	return 0; 
}
