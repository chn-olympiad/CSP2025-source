#include <bits/stdc++.h>
using namespace std;
long long n,a[100005],ans,cnt;
const long long mod = 998244353;
bool flag;
void dfs(long long x,long long maxn,long long sum,long long step)
{
//	printf("%lld %lld %lld %lld %lld\n",x,maxn,sum,step,ans);
	if (step >= 3)
		if (sum > maxn * 2)
			ans = (ans + 1) % mod;
	if (x == n)
		return ;
	for (int i = x + 1;i <= n;i++)
		dfs(i,max(maxn,a[i]),sum + a[i],step + 1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	bool flag = true;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (a[i] != 1)
			flag = false;
	}
	if (flag)
	{
		for (int i = 3;i <= n;i++)
		{
			ans = (ans + (n - i + 2) * (n - i + 1) / 2) % mod; 
		}
		cout << ans << endl;
		return 0;
	}
	for (int i = 1;i <= n;i++)
		dfs(i,a[i],a[i],1);
	cout << ans << endl;
	return 0;
}












/*
2025CSP-J游记

前面忘了 
8:30比赛开始
看T1，明显的签到题，直接暴力过。 
8:41写出T1
T2第一眼找规律，结果研究了半天没找出正解，发现n,m都小于等于10，直接暴力。 
T2的第四个点的m和a1黏在一起了，害的我找了半天错。 
9:01写出T2
T3想都没想打了个暴力，直接爆栈了。
然后发现答案有单调性，写了个二分答案，用一个前缀和（异或）维护，结果发现直接用前缀数组找更快。
最后用贪心写了，但是能过样例和1~5的测试点，6号点怎么样都比正确答案少一，最后不得不放弃T3。
9:44写出T3
T4马上想到线段树和滑窗，然后发现题目要求求所有答案，写了个爆搜。
10:25写出T4
发现T4有ai全为1的点，加了个特判。
11:45更改T4 
后面忘了 

--------------------------------------------------------------------------------------------------------------------------------------------------------

*/
