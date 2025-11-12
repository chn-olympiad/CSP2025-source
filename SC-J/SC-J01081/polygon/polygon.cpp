#include<bits/stdc++.h>
#define int long long  
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>=10){
		write(x/10);
	}
	putchar(x%10+'0');
}
const int mod=998244353;
int n,a[5005],ans,dp[5005][5005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=0;i<=n;i++){
		dp[i][0]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5000;j++){
			dp[i][j]=dp[i-1][j-a[i]]+dp[i-1][j];
			dp[i][j]%=mod;
		}
	}
	for(int i=3;i<=n;i++){
		for(int j=a[i]+1;j<=5000;j++){
			ans+=dp[i-1][j];
			ans%=mod;
		}
	}
	write(ans);
	return 0;	
}