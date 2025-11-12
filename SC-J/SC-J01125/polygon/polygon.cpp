#include<bits/stdc++.h>
#define ll unsigned long long 
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,mod=998244353;
	ll ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<(n+1)%mod;
}