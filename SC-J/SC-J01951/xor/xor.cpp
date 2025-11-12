#include<bits/stdc++.h>
#define N 500002
using namespace std;
int s,f;
char ch;
inline int read() {
	s=0,f=1;
	do if(ch=='-') f=-1;
	while((ch=getchar())<48);
	do s=(s<<3)+(s<<1)+(ch^48);
	while((ch=getchar())>47);
	return s*f;
}
inline void write(int x) {
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+48);
}
int n,k,a[N],sum[N],dp[N],ne[N],buc[(1<<21)],ans;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	n=read(), k=read();
	for(int i=1; i<=n; i++){
		a[i]=read();
		sum[i]=(sum[i-1]^a[i]);
		if(sum[i]==k) ne[i]=1;
		if(buc[k^sum[i]]!=0) ne[i]=buc[k^sum[i]]+1;
		buc[sum[i]]=i;
	}
	for(int i=1; i<=n; i++){
		dp[i]=dp[i-1];
		if(ne[i]==0) continue;
		dp[i]=max(dp[i],dp[ne[i]-1]+1);
	}	
	write(dp[n]);
	return 0;
}