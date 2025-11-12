#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1000000;
long long n,m,data1[MAXN],cnt,dp[MAXN][2],sum[MAXN],answer;
vector<long long> v[2 * MAXN];
long long search(long long x,long long y);
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for (long long i = 1;i <= n;i ++){
		scanf("%lld",&data1[i]);
	}
	for (long long i = n;i >= 1;i --){
		sum[i] = sum[i + 1] ^ data1[i];
		v[sum[i]].push_back(i);
	}
	for (long long i = 1;i <= n;i ++){
		sort(v[sum[i]].begin(),v[sum[i]].end());
	}
	for (long long i = 1;i <= n;i ++){
		dp[i][0] = max(dp[i - 1][0],dp[i - 1][1]);
		dp[i][1] = max(dp[i - 1][0],dp[i - 1][1]);
		long long position = search(i,m ^ sum[i + 1]);
		if (position != -1){
			dp[i][1] = max(dp[i][1],dp[position][0] + 1);
		}
	}
	for (long long i = 1;i <= n;i ++){
		answer = max(answer,max(dp[i][0],dp[i][1]));
	}
	printf("%lld\n",answer);
	return 0;
}
long long search(long long x,long long y){
	if (v[y].empty()){
		return -1;
	}
	long long L = 0,R = v[y].size() - 1,ans = -1;
	while (L <= R){
		long long mid = (L + R) >> 1;
		if (v[y][mid] <= x){
			ans = mid;
			L = mid + 1;
		} else {
			R = mid - 1;
		}
	}
	if (ans == -1){
		return ans;
	} else {
		return v[y][ans];
	}
}