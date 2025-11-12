#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
long long n,m,ans=1,cnt;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cnt+=(s[i]=='1');
	if(n==m){
		if(cnt==m)cout<<1;
		else cout<<0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=(ans*i)%mod;
		}
		cout<<ans;
	}
	return 0;
}