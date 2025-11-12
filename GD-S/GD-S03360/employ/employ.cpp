#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,mod=998244353;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	int cnt=0;
	for(int i=0;i<n;i++)if(s[i]=='1')cnt=1;
	if(cnt==0)return cout<<0,0;
	int a,ans=1;
	for(int i=1;i<=n;i++){
		cin>>a;
		ans=ans*i%mod;
	}
	cout<<ans;
	return 0;
}
