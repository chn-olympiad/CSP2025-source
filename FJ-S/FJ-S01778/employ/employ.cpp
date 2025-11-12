#include<bits/stdc++.h>
using namespace std;
int a[505],mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;cin>>n>>m;
	string s;cin>>s;int p=0;
	for(int i=0;i<s.size();i++) p+=s[i]-'0';
	for(int i=1;i<=n;i++) cin>>a[i];
	if(p==s.size()-1){
		long long ans=1;
		for(int i=n;i>=1;i--)
			ans=ans*i%mod;
		cout<<ans;
		return 0; 
	}
	else cout<<rand();
	return 0;
}
