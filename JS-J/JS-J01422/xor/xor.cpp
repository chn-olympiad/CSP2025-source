#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int a=0;char c;bool f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=0;
	do{a=a*10+(c^48);}while(isdigit(c=getchar()));
	return f?a:-a;
}
int n,k,xum=0;
int lst[1050000];
int dp[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	memset(lst,0xff,sizeof(lst));
	lst[0]=0;
	for(int i=1;i<=n;i++){
		xum^=read();
		dp[i]=dp[i-1];
		if(~lst[xum^k])dp[i]=max(dp[i],dp[lst[xum^k]]+1);
		lst[xum]=i;
	}
	printf("%d\n",dp[n]);
	return 0;
}
