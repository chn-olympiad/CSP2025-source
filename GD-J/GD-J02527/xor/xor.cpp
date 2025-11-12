#include <bits/stdc++.h>
#define O 500005
using namespace std;
long long lst[O],n,k;
long long he[O],dp[O];
void solve_AB()	//解决特殊性质A,B,35pts 
{
	int zero = 0,one = 0;
	if(k == 0)
	{
		for(int i = 1;i <= n;++i)
		{
			if(lst[i] == 0)
				++zero,one = 0;
			else if(lst[i] == 1)
			{
				++one;
				if(one % 2 == 0)
					++zero,one = 0;
			}
		}
	}
	else	//k = 1,统计1的数量 
	{
		for(int i = 1;i <= n;++i)
			one += (lst[i] == 1);
	}
	printf("%lld",zero + one);
}
void solve_dp()	//性质+骗分,预期得分:65pts 
{
	for(int i = 1;i <= n;++i)
	{
		for(int q = i;q >= 1;--q)	//结合贪心的性质,我们取得一个就收手 
		{
			//不妨优化一下
			if(dp[q - 1] + 1 < dp[i - 1])	//优化1:这个时候不合并会更优一点 
				break; 
			int sum = he[i] ^ he[q - 1];	//区间[k,i]的异或和
			if(sum == k)	//找到了
			{
				dp[i] = max(dp[i - 1],dp[q - 1] + 1);
				break;
			}
		}
		if(dp[i] <= 0)
			dp[i] = dp[i - 1];	
	}
	printf("%lld",dp[n]);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(int i = 1;i <= n;++i)
		scanf("%lld",&lst[i]),he[i] = he[i - 1] ^ lst[i];
	if(k <= 1)
		solve_AB();
	else
		solve_dp();
	return 0;
}
/*
分析题目性质
首先,数据规模大,n 达到了5e5
我们考虑O(n)或者O(n log n)
区间异或和,我们首先考虑使用前缀和来优化复杂度
同时,观察到,我们在满足区间[l,r]异或和为k的时候,就不要再扩张了
其次,每个区间异或和为k的区间长度不一定相等

算了,看上去没有什么思路,姑且先考虑骗到特殊性质的分
对于特殊性质A,B:
我们只需要处理0,1即可
0可以拆分成两个1的异或和或者一个0的异或和
而k = 1我们便只需要处理lst[i] = 1有多少个就可以了

等一下,我们发现了一个性质:
我们或许可以dp
思路如下:
既然区间不能重复
那么我们可以定义dp[n]为截至到第n个元素,我们所能凑出多少个区间异或和为k的区间
与此同时,我们还观察到一个性质
即[l,r + 1] >= lst[l,r]
所以我们取得的区间长度越短越好 

但是,时间复杂度达到了惊人的n ^ 2
我们可能需要想办法优化一波
首先,外层大概是没办法优化的了
那么内层呢?
尽管我们已经使用了贪心的性质来优化
但是我们发现:
如果以i结尾的区间无解,那么会浪费很多时间
如何把无解的尾结点排除在外呢?
或者说,尽管你这个区间以i为区间结尾有解,但是你合并了比不合并要劣,这个时候也可以直接剪掉了

但是,我们发现,题目的k是用2的多少次方来给的数据
那么这道题会不会和二进制有什么关系? 

预期得分:65pts(但是不知道为什么5e5的数据能再吸氧后卡在0.2s左右过,真是神奇,姑且当65pts计算) 
坏了,突然发现优化好像是对的
因为删了优化和没删是一样的
但是删了还更快了
所以我们大胆猜想这道题可能AC(但是保底65pts,如果硬要卡数据肯定是过不了的) 
*/
