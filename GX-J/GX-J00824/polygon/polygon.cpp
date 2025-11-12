#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,mod=998244353;
int n;
int a[N];
void solve1(){
	sort(a+1,a+1+n);
	if(a[1]+a[2]>a[3]) cout<<1;
	else cout<<0;
	return;
}
void solve114514(){
	long long ans=0;
	for(int i=3;i<=n;i++){
		int x=n;
		long long sum=1;
		for(int j=1;j<=i;j++){
			sum*=x;
			sum/=j;
			sum%=mod;
			x--;
		}
		ans+=sum;
		ans%=mod;
	}
	cout<<ans%mod;
}		
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3) solve1();
	else solve114514();
	return 0;
}
