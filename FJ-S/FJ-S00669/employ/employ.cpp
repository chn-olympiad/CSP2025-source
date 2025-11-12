#include<bits/stdc++.h>
#define ll long long
#define il inline
using namespace std;
void read(int &n){
	int x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';c=getchar();
	}n=x*f;
}
void read(ll &n){
	ll x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';c=getchar();
	}n=x*f;
}
const int N=19,mod=998244353;
int n,m;
int c[N];
char s[505];
ll dp[N][N][1<<N];int cnt[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n);read(m);
	scanf("%s",s);
	for(int i=0;i<n;i++)read(c[i]);
	dp[0][0][0]=1;
	for(int i=0;i<(1<<n)-1;i++){
		cnt[i]=cnt[i>>1]+(i&1);
		for(int j=0;j<=cnt[i]+1;j++){//前面的拒绝次数 
			for(int k=0;k<=cnt[i]+1;k++){//成功次数 
				if(!dp[j][k][i])continue;
				for(int l=0;l<n;l++){
					if((i|(1<<l))==i)continue;
					if(c[l]>j&&s[cnt[i]]=='1'){
//						cout<<i<<' '<<j<<' '<<k<<' '<<l<<endl;
						dp[j][k+1][i|(1<<l)]+=dp[j][k][i];
						dp[j][k+1][i|(1<<l)]%=mod;
					}else{
						dp[j+1][k][i|(1<<l)]+=dp[j][k][i];
						dp[j+1][k][i|(1<<l)]%=mod;
					}
				}
			}
		}
	}
	ll ans=0;
	for(int i=0;i<=n;i++){
		for(int j=m;j<=n;j++){
			ans=ans+dp[i][j][(1<<n)-1];ans%=mod;
		}
	}
	cout<<ans;
	return 0;
}

