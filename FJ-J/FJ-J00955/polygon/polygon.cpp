/*
孩子们9:30t4我来了 

他这个多边形边数没限制那我不就可以直接排序后枚举最大值
那问题就转化成了求序列1~i-1中有多少个子序列S，使sum a_{S_j}>a_i
记dp[i]表示1~i的答案
好难统计 
欸不对n和a都是5000级别的
那我就可以直接记dp[i][j]表示1~i中子序列和>=j的序列数
哦哦不对我可以直接记=j就好了
然后树状数组统计一下答案不就好了 
欸好严峻的问题
sum a<=25000000
炸了
欸如果直接记 dp[i][j]表示1~i中子序列和>=j的序列数好像也可以直接求啊 
ok小样例过了 ，树状数组都不用了 
欸忘取模了 
拿下 
去打对拍了

11:00孩子们我回来了 
我想吃士力架 
这次比赛怎么这么水
不行我不能说大话
但愿不会爆0
希望下午不要太难
不然我就afo了 

去上厕所的路上看到ljf都快睡上了

11：22算了打个指数级的暴力对拍吧 
11:33ok对拍了几组都没问题 
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD=998244353; 
ll maxa;
ll a[5001],dp[2][5001];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	sort(a+1,a+n+1);
	ll ans=0,fl=0;
//	for(int i=0;i<=a[1];i++)
//	{
//		dp[fl][i]=1;
//	}
	for(int i=1;i<=n;i++)
	{
		ans+=dp[fl][a[i]+1];
		ans%=MOD;
//		memset(tree,0,sizeof(tree));
		for(int j=0;j<=maxa+1;j++)
		{
			dp[fl^1][j]=dp[fl][j]+dp[fl][max(j-a[i],0ll)];
			if(a[i]>=j)
			{
				dp[fl^1][j]++;
			}
			dp[fl^1][j]%=MOD;
//			change(j-1,dp[fl^1][j]);
		}
//		for(int j=0;j<=maxa;j++)
//		{
//			cout<<"T "<<dp[fl^1][j]<<" N.M.T "<<j<<"; ";
//		}
//		cout<<'\n';
		fl^=1;
//		cout<<ans<<' ';
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<i;j++)
//		{
//			if(a[j]>a[i])
//			{
//				ans--;
//			}
//		}
//	}
	cout<<ans;
}
