#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
long long dp[1000005][20];
string s;
int ksm(int zs){
	if(zs==0)
		return 1;
	int ls=ksm(zs/2);
	ls*=ls;
	if(zs%2)
		ls*=2;
	return ls;
}
int main(){
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)
		cin>>c[i];
	if(n<=18){
		long long ans=0;
		dp[0][0]=1;
		for(int i=1,sl;i<ksm(n);i++){
			sl=0;
			for(int j=i;j>0;j/=2){
				if(j%2)
					sl++;
			}
			for(int j=1,l=0;j<=i;j*=2,l++){
				if(i%(j*2)/j){
					for(int k=0;k<=n;k++){
						if(s[sl-1]=='0'||c[l]<=sl-k)
							dp[i][k]=(dp[i][k]+dp[i-j][k])%998244353;
						else if(k!=0)
							dp[i][k]=(dp[i][k]+dp[i-j][k-1])%998244353;
					}
				}
			}
		}
		for(int i=m;i<=n;i++)
			ans=(ans+dp[ksm(n)-1][i])%998244353;
		printf("%lld",ans);
	}else if(m==n){
		bool cl=1;
		for(int i=0;i<n;i++){
			if(s[i]=='0')
				cl=0;
			if(c[i]==0)
				cl=0;
		}
		if(cl){
			long long ans=1;
			for(int i=0;i<n;i++)
				ans=ans*(i+1)%998244353;
			printf("%lld",ans);
		}else
			printf("0");
	}
	return 0;
}
