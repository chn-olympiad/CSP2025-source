#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e2+5,mod=998244353;
char ch[N];
int s[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;cin>>n>>m;
	scanf("%s",ch+1);
	int tj=0,zero=0;
	for(int i=1; i<=strlen(ch+1); i++)if(ch[i]=='1')tj++;
	for(int i=1; i<=n; i++){
		cin>>s[i];
		if(s[i]==0)zero++;
	}
	if(n-zero<m){cout<<0;return 0;}
	int ans=1;
	for(int i=1; i<=n; i++)ans=ans*i%mod;
	cout<<ans;
	return 0;
}
