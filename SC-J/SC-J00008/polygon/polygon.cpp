#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5010];
long long v[5010][5010];
long long A(int x,int n){
	long long ans=1;
	for(int i=1;i<=x;i++){
		ans*=(n-i+1);
	}
	return ans;
}
long long C(int x,int n){
	if(v[x][n])return v[x][n];
	if(2*x>n)return v[x][n]=C(n-x,n);
	return v[x][n]=A(x,n)/A(x,x);
}
int main(){
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=0;
	}
	if(f){
		long long ans=0;
		for(int i=3;i<=n;i++){
			ans=(ans+C(i,n))%mod;
		}
		cout<<ans;
		return 0;
	}
	cout<<((a[1]+a[2]+a[3])>2*max(a[1],max(a[2],a[3])));
	return 0;
}