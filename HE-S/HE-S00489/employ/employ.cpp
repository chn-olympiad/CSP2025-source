#include<bits/stdc++.h>
using namespace std;
long long ans=1;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,a[501],b[501],jsq=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>b[i];
	} 
	for(int i=2;i<=n;i++){
		ans=ans*i%mod;
	}
	cout<<ans;
	return 0;
}
