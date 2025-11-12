#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long ans;
int a[5010];

void dfs(int now,int sum,int k,bool flag)
{
	if(flag)
	{
		k--;
		sum+=a[now];
	}
	if(k==0)
	{
		if(sum>2*a[now])ans++;
		cout<<ans;
		return;
	}
	dfs(now+1,sum,k,1);
	dfs(now+1,sum,k,0);
	return;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	/*sort(a+1,a+1+n);
	for(int i=n;i>=3;i--)
	{
		dfs(i,0,i,1);
		dfs(i,0,i,0);
	}
	printf("%lld",ans%mod);*/
	for(int i=3;i<=n;i++)
	{
		ans+=(1+n)*n/2-i;
	}
	printf("%lld",ans%mod);
	return 0;
}
/*
对于我来说,对与否不重要,重要的是思考的过程和价值

对输入数组考虑排序这样我们就可以用a[i]代替求最大值了
由于n小于等于5000,考虑暴力
然后从n开始遍历,代表n边形
...
又或者,可以dfs?
dfs(总和,还能选的个数,是否选择)
啧,不对
让我看看还有什么细节
	|---->i不能小于3
	|---->会有重复的数
为啥我的ans不输出啊
还是来看看特殊性质吧:
	所有a[i]均等于1,而且仅算下标集合不同，所以这是个排列数
	3~n都可以,所以ans=...
尽力了
*/
