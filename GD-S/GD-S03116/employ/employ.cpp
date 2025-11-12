#include<bits/stdc++.h>
using namespace std;
int n,m,a[550],f[550][550],ans,mod=998244353;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=0;k<j;k++){
				f[j][k]=(f[j][k]+f[j-1][k])%mod;
				if(k>=a[i]){
					f[j][k+1]=(f[j][k+1]+f[j-1][k])%mod;
				}
			}
		}
	} 
	for(int i=0;i<=n-m;i++){
		ans=(ans+f[n][i])%mod;
	}
	cout<<ans;
	return 0;
} 
