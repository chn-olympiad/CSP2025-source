#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5050;
const int mod=998244353;
ll n;
ll a[N],s[N];
ll jc=1,c;
bool r=true;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) r=false;
	}
	if(n==3){
		int d=max(a[1],max(a[2],a[3]));
		if(2*d<a[1]+a[2]+a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	ll sum=0;
	if(r==true){
		for(int i=3;i<=n;i++){
			jc=1,c=1;
			for(int j=i+1;j<=n;j++){
				jc*=j;
			}
			for(int j=1;j<=n-i;j++){
				c*=j;
			}
			sum+=(jc/c)%mod;
		}
		cout<<sum%mod;
		return 0;
	}
	cout<<n*(n-1)/2-1;
	return 0;
}
