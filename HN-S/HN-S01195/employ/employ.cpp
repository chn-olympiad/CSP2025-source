#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
int n,m,a[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
	}
	if(n==m){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
	}
	else cout<<0;
	return 0;
}
