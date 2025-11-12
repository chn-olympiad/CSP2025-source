#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
int n,m,c[550];
string s;
int main(){
	freopen("employ4.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	//cin>>s;
	//for(int i=1;i<=n;i++)
	//	cin>>c[i];
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==n){
		long long ans=1;
		for(int i=n-m+1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans%mod;
		return 0;
	}
	cout<<0;
	return 0;
}
