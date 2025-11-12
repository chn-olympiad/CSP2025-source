#include <bits/stdc++.h> 
using namespace std;

//思路：应该是dp 
/*
1 2 3 4 5
(2,3,4),(2,4,5),(3,4,5),(1,2,3,4),(1,2,3,5),(1,2,4,5),(1,3,4,5),(2,3,4,5),(1,2,3,4,5)
q = 1 3 6 10 15
dp[i][j]表示在前i个数中选j个数能组成多少数组 
 0 1 2 3 4 5 j
 1 0 0 0 0 0
 2 0 0 0 0 0
 3 0 0 0 0 0
 4 0 0 1 2 0
 5 0 0 3 8 9
 i
似乎不对 寄 
*/ 
int mod = 998244353,a[5005],n;
long long dp[5005][5005] = {},q[5005] = {};

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		q[i] = q[i-1]+a[i];
	}
	sort(a,a+n);
	for(int i = 3;i<=n;i++){
		for(int j = 3;j<=n;j++){
			if(q[i]-q[j-i] > a[i]*2) dp[i][j] ++;
			dp[i][j] += dp[i][j-1];
		}
	}
	cout << dp[n][n]%mod;
	return 0;
}
/*
距考试结束还有20分钟，大抵是寄了 
T1T2比较简单，拿个180pts还是没问题的 
T3已经把查区间代码做出来了，可思考良久，不会做去重复，能拿10pts就不错了
T4dp公式绞尽脑汁想不出来，不想想了，摆烂吧 

请欣赏【程序员普奇】 
你相信dp吗 
我很佩服第一个打出f[i][j]的人，因为那说不定会WA呢 
[Hello World]
[A+B problem]
[字符串]
[布尔值]
[模拟]
[递归]
[高精度]
[动态规划] 
话已至此
【MADE IN C++】 !!!
*/
