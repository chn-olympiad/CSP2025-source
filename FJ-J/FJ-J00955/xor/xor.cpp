/*
终于有点有思考含量的题了。
令dp[i]表示序列1~i的答案
n^2dp正确性包过。
考虑优化，想着推斜率（？）
哦可以贪心选取，一个i一定是选位置最接近他的j
哦哦哦有a^b=c,\notexist d\not=b, a^b=c
一看a是10^6级别的
所以可以直接记 pos[i]表示最右边的一个j，使i^sum[pos[i]]=K
然后没了。
欸一个i所更新的pos只对后面有效哦哦哦
线段树（？）
ok换一下顺序就可以了
欸怎么第五个样例挂了
哦这时候dp[i]表示的是以i为结尾有一个序列的最大值
所以要记一个maxdp。 

10：52孩子们我回来打对拍了 
算了暴力不会打，随便测点数据吧 
但愿没问题 

欸这题是不是可以打状压（？） 
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXA=(1<<21);
int pos[MAXA];
int dp[500001],sum[500001],maxdp[500001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
//	dp[0]=-1;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		sum[i]=sum[i-1]^a;
		dp[i]=maxdp[pos[sum[i]]]+((sum[i]^sum[pos[sum[i]]])==k);
		maxdp[i]=max(maxdp[i-1],dp[i]);
//		cout<<sum[i]<<' '<<dp[i]<<'\n';
		pos[k^sum[i]]=i;
	}
	cout<<maxdp[n];
}
