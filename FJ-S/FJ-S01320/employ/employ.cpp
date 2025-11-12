#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[505],dp[505][505];
string s;
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++) ans=ans*i%mod;
	cout<<ans;
}
/*
*/
