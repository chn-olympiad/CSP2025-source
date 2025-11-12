#include <bits/stdc++.h>
#define O 5005
const long long mod = 998244353;
long long lst[O],n;
using namespace std;
long long dfs(long long idx,long long ch,long long maxx,long long sum)	//预期得分:40pts 
{
	if(idx == n + 1)	//边界条件 
	{
		if(ch < 3)
			return 0;
		if(sum > maxx * 2)
			return 1;
		return 0;
	}
	//对于某一条边,都有选或不选两种情况
	long long Q = 0;
	Q += dfs(idx + 1,ch,maxx,sum) % mod;
	Q += dfs(idx + 1,ch + 1,lst[idx],sum + lst[idx]) % mod;
	return Q % mod;
}
long long C(long long a,long long b)
{ 
	long long sum = 1;
	vector <long long> v1;	//不直接计算阶乘,防止爆long long
	//所以我们使用辗转相除法,计算排列
	//就是先把每个要相乘的数字存储起来,然后用要除的数字一个一个辗转相除
	//最后把所得的商相乘 
	for(long long i = 1;i <= b;++i)
		v1.push_back(a - i + 1);
	for(long long i = 2;i <= b;++i)
	{
		long long num = i,zhan;
		for(long long k = 0;k < v1.size();++k)
		{
			if(v1[k] == 1)
				continue;
			zhan = __gcd(max(num,v1[k]),min(num,v1[k]));
			v1[k] /= zhan;
			num /= zhan;
			if(num == 1)	//除到1就没有必要再除了 
				break;
		}
	}
	for(int i = 0;i < v1.size();++i)
		sum = ( (v1[i] % mod) * (sum % mod) ) % mod;
	return sum;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i = 1;i <= n;++i)
		scanf("%lld",&lst[i]);
	sort(lst + 1,lst + 1 + n);
	if(n <= 29)
		printf("%lld",dfs(1,0,0,0) % mod);
	else
	{
		long long sum = 0;
		for(int i = 3;i <= n;++i)
		{
			sum += C(n,i) % mod;
			sum %= mod;
		}
		printf("%lld",sum);
	}
	return 0;
}
/*
n <= 5000
考虑dp
考虑二维dp数组
我们不难看出,题目要求我们表示的至少有2个量:
1.我们当前选到了第几条边
2.我们当前的图形是几边形

但是,我们再探究dp[i][k]的转移方程时,我们还需要考虑
不考虑了,直接找特殊性质
观察到,15 ~ 20有ai <= 1
那么这种情况,我们也是非常轻松就能秒掉,毕竟这个时候就是排列组合问题
C(3,n) + C(4,n) + C(5,n) + …… + C(n,n)
因为这个时候没有边长条件的限制,即正多边形
预期得分
暴力dfs -> 1 ~ 10,预期得分:40pts
排列组合 -> 15 ~ 20,预期得分:24pts
总得分:64pts 
*/
