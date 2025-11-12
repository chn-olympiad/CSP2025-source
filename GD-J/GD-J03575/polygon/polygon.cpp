#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=5005,MAXA=5000;
const int p=998244353;
int n,A[MAXN];
long long dp[MAXN],tmp[MAXN];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&A[i]);
	sort(A+1,A+n+1);
	dp[0]=1;
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=A[i]+1;j<=MAXA;j++) ans+=dp[j],ans%=p;
		for(int j=0;j<=MAXA;j++) tmp[j]=dp[j];
		for(int j=0;j<=MAXA;j++){
			if(j+A[i]<MAXA) dp[j+A[i]]+=tmp[j],dp[j+A[i]]%=p;
			else dp[MAXA]+=tmp[j],dp[MAXA]%=p;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
