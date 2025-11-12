#include<bits/stdc++.h>
using namespace std;
int n,m,c[501],a[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		a[i]=x-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	long long ans=1,mod=998244353;
	for(int i=1;i<=n;i++){
		ans=ans*i%mod;
	}
	cout<<ans;
}
