#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,j,l,r,a[1000000+10],b[1000000+10],x,o,z,ln,rl,ans;
struct doge{
	ll l,r;
};
vector<doge> v;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k>>a[1];
	b[1]=a[1];
	o+=(a[1]==1);
	z+=(a[1]==0);
	for(ll i=2;i<=n;++i){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
		o+=(a[i]==1);
		z+=(a[i]==0);
	} 
	if(o==n){
		if(k==0) cout<<n-1;
		return 0;
	}
	if(o+x==n){
		for(int i=1;i<=n;++i){
			if(a[i]==1){
				ans++;
			}
		} 
		if(k==0){
			cout<<ans-1;
		}
		else{
			cout<<ans+ans/3;
		}
		return 0;
	}
	v.push_back({0,n+1});
	for(ll i=1;i<=n;++i){
		j=i;
		x=0;
		int fl(i);
		while(j<=n){
			x=b[i-1]^b[j];
			if(a[j]==0) fl++;
			if(x==k and ((fl!=j and k!=0) or i==j)){
				v.push_back({i,j});
				break;
			}
			j++;
		} 
	}
	v.push_back({n+1,0});
	for(ll i=1;i<v.size()-1;++i){
		if(v[i].r-v[i+1].l<=1) ans++;
	}
	cout<<ans;
	return 0;
} 
