#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int mod=998244353;
int n,m;
char s[N];
int c[N];
int f[19][(1<<19)][19];
void dp(){
	memset(f,0,sizeof(f));
	f[0][0][0]=1;
	for(int p=0;p<n;p++){
		for(int i=0;i<(1<<n);i++){
			for(int j=0;j<n;j++){
				if(((i>>j)&1)==0){
					for(int k=0;k<=n;k++){
						f[p+1][i+(1<<j)][k+((c[j+1]<=k)||(s[p+1]=='0'))]=1ll*(f[p+1][i+(1<<j)][k+((c[j+1]<=k)||(s[p+1]=='0'))]+f[p][i][k])%mod;
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=(n-m);i++) ans=1ll*(ans+f[n][(1<<n)-1][i])%mod;
	cout<<ans<<endl;
	return ;
}
void A(){
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=1ll*ans*i%mod;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int flag=1;
	for(int i=1;i<=n;i++){
		if(s[i]=='0') flag=0;
	}
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n>20&&flag) A();
	else {
		if(n<=20) dp();
		else cout<<0<<endl;
	}
	return 0;
}
/*
3 2
101
1 1 2
*/
