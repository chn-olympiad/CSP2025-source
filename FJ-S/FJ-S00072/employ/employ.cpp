#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int mod=98244353;
int n,m,c[600],x[600],s1,s,ans;
char b[600];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,b+1);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)x[i]=i;
	do{
		s1=s=0;
		for(int i=1;i<=n;i++){
			if(b[i]=='0')s1++;
			else if(c[x[i]]<=s1)s1++;
			else s++;
		}
		if(s>=m){
			ans++;
		}
	}while(next_permutation(x+1,x+n+1));
	printf("%d\n",ans);
	return 0;
}
/*
3 2
101
1 1 2
*/
/*#include<iostream>
#include<cstdio>
using namespace std;
const int mod=98244353;
int n,m,n1,c[600],sc[2000],x[600],s1,dp[30][30][30][30];
char b[600];
int main(){
	scanf("%d%d%s",&n,&m,b+1);
	for(int i=1;i<=n;i++){
		if((b[i]=='1'))x[++n1]=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		sc[c[i]]++;
	}
	for(int i=1;i<=n+n1;i++)sc[i]+=sc[i-1];
	s1=1;
	for(int i=1;i<=n-n1;i++)s1=1ll*s1*i%mod;
	dp[0][0][0][0]=1;
	for(int i=0;i<n1;i++){
		for(int j=0;j<=n1;j++){
			for(int k=0;k<=n1;k++){
				for(int lst=0;lst<=n1;lst++){
					if(!dp[i][j][k][lst])continue;
					for(int l=0;l<=min(k,sc[x[i+1]+j]-sc[lst]);l++){
						dp[i+1][j][k-l]=(dp[i+1][j][k-l]+dp[i][j][k]*C())
					}
				}
			}
		}
	}
	return 0;
}*/
