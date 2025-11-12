#include<bits/stdc++.h>
#define ll long long
const int N=19,M=3e5,mod=998244353;
int c[1000],d[N];
ll dp[N][N][M],pw[1000];
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,f=1;
	ll sum=0;
	string s;
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(c[i]==0) f=0;
	}
	sort(c+1,c+n+1);
	dp[0][0][0]=1,pw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=pw[i-1]*2%mod;
	if(m==n){
		printf("%lld",pw[n]*f);
		return 0;
	}	
	for(int i=0;i<n;i++){
		for(int id=0;id<pw[n];id++){
			int f=id,s1=0,s2=0;
			while(f) d[++s1]=f%2,s2+=f%2,f/=2;
			if(s2!=i) continue;
			for(int j=0;j<=i;j++){
				for(int z=1;z<=n;z++){
					if(z>s1||d[z]==0){
						if(c[z]>i-j&&s[i]=='1')
							dp[i+1][j+1][id+pw[z-1]]+=dp[i][j][id];
						else dp[i+1][j][id+pw[z-1]]+=dp[i][j][id];
						dp[i+1][j+1][id+pw[z-1]]%=mod,dp[i+1][j][id+pw[z-1]]%=mod;
					}
				}
			}
		}
	}
	for(int i=m;i<=n;i++) sum+=dp[n][i][pw[n]-1],sum%=mod;
	printf("%lld",sum);
	return 0;
} 
