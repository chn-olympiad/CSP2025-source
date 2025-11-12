#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 5;
inline long long read(){
	int f = 0,k = 0;
	char c = getchar();
	while(!isdigit(c)){
		f |= c == '-';
		c = getchar();
	}
	while(isdigit(c)){
		k = k * 10 + c - '0';
		c = getchar();
	}
	return f ? -k : k;
}
long long n,k,ans;
long long a[N],s[N],dp[N];//以第i个数结尾的区间数量最大值 
int main(){//DP 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n = read(),k = read();
	bool fl0 = 0,fl1 = 0,fl2 = 0;
	for(int i = 1;i <= n;i++){
		a[i] = read();
		if(a[i] == 1) fl1 = 1;
		if(a[i] == 0) fl0 = 0;
		if(a[i] > 1) fl2 = 0;
	}
	if(!fl2 && fl1 && fl0){//全是01
		int tot = 0;
		if(k == 0){
			for(int i = 1;i <= n;){
				if(a[i] == 0){
					++tot;
					++i;
				}
				else if(i < n && a[i] == 1 && a[i + 1] == 1){
					++tot;
					i += 2;
				}
			}
		}
		else {
			for(int i = 1;i <= n;i++){
				if(a[i] == 1){
					++tot;
					++i;
				}
				else if(i < n && a[i] == 0 && a[i] == 1){
					++tot;
					i += 2;
				}
			}
		}
		printf("%lld",tot);
		return 0;
	}
	s[0] = 0;
	for(int i = 1;i <= n;i++){
		s[i] = s[i - 1] ^ a[i];
		if(s[i] == k) dp[i] = 1;
	}
	for(int i = 1;i <= n;i++){
		for(int j = i - 1;j >= 1;j--){
			if((s[i] ^ s[j]) == k){
				dp[i] = max(dp[i],dp[j] + 1);
			}
			else dp[i] = max(dp[i],dp[j]);
		}
	}
	printf("%lld",dp[n]);
	return 0;
}
