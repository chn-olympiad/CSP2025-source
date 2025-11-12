#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int a=0;char c;bool f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=0;
	do{a=a*10+(c^48);}while(isdigit(c=getchar()));
	return f?a:-a;
}
const int Mod=998244353,MAX=1e4+1;
int n,sum=0,ans=0;
int a[5010];
int tmp[10010][2];
int dp[10010][2];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=min(sum,MAX);j++){
			(tmp[j][0]+=(dp[j][0]+dp[j][1])%Mod)%=Mod;
			(tmp[min(j+a[i],MAX)][1]+=(dp[j][0]+dp[j][1])%Mod)%=Mod;
		}
		sum+=a[i];
		for(int j=0;j<=min(sum,MAX);j++){
			dp[j][0]=tmp[j][0],tmp[j][0]=0;
			dp[j][1]=tmp[j][1],tmp[j][1]=0;
		}
		for(int j=a[i]*2+1;j<=min(sum,MAX);j++)(ans+=dp[j][1])%=Mod;
	}
	printf("%d\n",ans);
	return 0;
}
