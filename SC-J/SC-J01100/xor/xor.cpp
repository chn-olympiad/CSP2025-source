#include <bits/stdc++.h>
using namespace std;
int in(){
	int w = 0 , f = 1;
	char ch = getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f = -1;
		ch = getchar();
	}
	while('0'<=ch&&ch<='9'){
		w = (w<<3)+(w<<1)+(ch&15);
		ch = getchar();
	}
	return w*f;
}
const int N = 5e5+15 , MAXN = (1<<21)+15;
int n,k,l[MAXN],dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n = in() , k = in();int sum = 0;
	for(int i = 1 ; i<=n ; i++){
		sum ^= in() , dp[i] = dp[i-1];
		if(sum==k||l[sum^k])
		dp[i] = max(dp[i],dp[l[sum^k]]+1);
		l[sum] = i;
	}
	printf("%d",dp[n]);
	return 0;
}