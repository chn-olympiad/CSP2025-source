#include<bits/stdc++.h>
using namespace std;
int read(){
	int ret=0,op=1;char in=getchar();
	while(!isdigit(in)){if(in=='-'){op=-1;}in=getchar();}
	while(isdigit(in)){ret=(ret<<3)+(ret<<1)+(in^48);in=getchar();}
	return ret*op;
}
int lent,knum,mx,ret;
int val[500010],pre[500010];
int dp[500010],dis[2000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	lent=read();knum=read();
	for(int i=1;i<=lent;i+=1){
		val[i]=read();
		pre[i]=pre[i-1]^val[i];
	}
	dis[0]=1;
	for(int i=1;i<=lent;i+=1){
		if(dis[knum^pre[i]]){
			dp[i]=1+dp[dis[knum^pre[i]]-1];
		}
		dp[i]=max(dp[i],dp[i-1]);
		dis[pre[i]]=i+1;
	}
	printf("%d",dp[lent]);
	return 0;
}