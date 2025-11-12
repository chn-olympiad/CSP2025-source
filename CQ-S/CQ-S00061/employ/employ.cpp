#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,f[300100][30],c[100100],cnt,ans;
const int mod=998244353;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	if(n<=18){
		for(int i=1;i<=n;i++)cin>>c[i];
		f[0][0]=1;
		for(int i=1;i<(1<<n);i++){
			cnt=0;
			for(int j=0;j<n;j++){
				if(i&(1<<j))cnt++;
			}
			for(int j=0;j<n;j++){
				if(!(i&(1<<j)))continue;
				if(s[cnt-1]=='0'){
					for(int k=1;k<=cnt;k++)f[i][k]=(f[i][k]+f[i^(1<<j)][k-1])%mod;
				}
				else{
					for(int k=0;k<=cnt;k++){
						if(c[j+1]==k)continue;
						if(c[j+1]<k)f[i][k]=(f[i][k]+f[i^(1<<j)][k-1])%mod;
						else f[i][k]=(f[i][k]+f[i^(1<<j)][k])%mod;
					}
				}
			}
		}
		for(int i=0;i<=n-m;i++)ans=(ans+f[(1<<n)-1][i])%mod;
		cout<<ans;
	}
	else{
		ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%mod;
		}
		cout<<ans;
	}
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
