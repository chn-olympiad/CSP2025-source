#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long ans=1;
int n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	int a;
	for(int i=1;i<=n;i++) cin>>a;
	for(int i=1;i<=n;i++) ans=ans*i%mod;
	cout<<ans;
	return 0;
}
	
