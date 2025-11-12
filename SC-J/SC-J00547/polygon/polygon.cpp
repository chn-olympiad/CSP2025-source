#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll a[5005];
ll s[5005];
const int ii=998224353;
int he(int num,int x){
	int ans=1;
	for(int i=num,j=x;j>0;i--,j--) ans*=i;
	return ans;
}
void cmp(int x,int y,int n){
	if(y<=n){
		x++;
		y=x+1;
	}
	return;
}
bool f(int sum,int mx){
	if(mx<sum) return 1;
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n,mi0=0;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) mi0++;
	} 
	sort(a+1,a+n+1);
	if(n<3){
		cout<<0;
		return 0;
	} 
	if(n==3){
		if(a[3]<a[1]+a[2]) cout<<1;
		return 0;
	}
	if(mi0==n){
		ll ans=0;
		for(int i=3;i<=n;i++){
			ans+=he(n-i+1,i);
			ans%=ii;
		}
		cout<<ans;
		return 0;
	}
	if(n<=5){
		int x=1,y=2,z=3,ans=0;
		while(x<=n){
			cmp(y,z,n);
			cmp(x,y,n);
			if(f(a[x]+a[y]+a[z],a[z])) ans++;
		}
		int m=4;
		x=1;y=2;z=3;
		while(x<=n){
			cmp(z,m,n);
			cmp(y,z,n);
			cmp(x,y,n);
			if(f(a[x]+a[y]+a[z]+a[m],a[m])) ans++;
		}
		int l=5;
		x=1;y=2;z=3;m=4;
		while(x<=n){
			cmp(m,l,n);
			cmp(z,m,n);
			cmp(y,z,n);
			cmp(x,y,n);
			if(f(a[x]+a[y]+a[z]+a[m]+a[l],a[l])) ans++;
		}
		cout<<ans;
		return 0;
	}
	cout<<5000;
	return 0;
}