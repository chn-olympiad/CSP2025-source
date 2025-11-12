#include<bits/stdc++.h> 
#define int long long
using namespace std;
inline int read(){
	char ch;
	int sum=0,x=1;
	ch=getchar();
	while(ch<'0'||(ch>'9')){
		if(ch=='-')x=-1;
		ch=getchar(); 
	}
	while((ch>='0')&&(ch<='9')){
		sum=(sum<<3)+(sum<<1)+(ch^48);
		ch=getchar();
	}
	return sum*x;
}
//zzzzzz
int n,k,x,a[550050],sk[550050],sn[(1<<22)],dp[550050];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		sk[i]=(sk[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		x=(sk[i]^k);
		if(sn[x]!=0){
			dp[i]=max(dp[i],dp[sn[x]]+1);
		}else if(x==0){
			dp[i]=max(dp[i],1ll);
		}
		sn[sk[i]]=i;
	}
	cout<<dp[n];
	return 0;
}
