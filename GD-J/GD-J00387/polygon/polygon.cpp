#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+7;
const int mod=998224353;
int n,maxn=0;
int a[N];
int c(int x,int y)
{
	if(x==0) return 1;
	int s=1;
	for(int i=y;i>=y-x+1;i--) s*=i,s%=mod;
	for(int i=1;i<=x;i++) s/=i,s%=mod;
	return s%mod;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],maxn=max(maxn,a[i]);
	sort(a+1,a+1+n);
	if(maxn==1)
	{
		int sum=0;
		for(int i=3;i<=n;i++) sum+=c(i,n),sum%=mod;
		cout<<sum;
		return 0;
	}
	int sum=0;
	for(int k=3;k<=n;k++)
	{
		bool f=0;
		for(int j=k-1;j>=1;j--)
		{
			for(int i=1;i<j;i++)
			{
				if(a[i]+a[j]>a[k])
				{
					int c1=0,c2=0;
					for(int p=0;p<=i-1;p++) c1+=c(p,i-1),c1%=mod;
					for(int p=0;p<=j-i-1;p++) c2+=c(p,j-i-1),c2%=mod;
					sum+=c1*c2;
					sum%=mod;
					f=1;
					break;
				}
			}
			if(f) break;
		}
	}
	cout<<sum;
	return 0;
}
/*
没有圆周的钟  失去旋转意义
下雨这天 好安静
远行没有目的  距离不是问题 
不爱了 是你的谜底
我占据格林威治守候着你
在时间标准起点回忆过去
你却在永夜的极地旅行
等爱在失温后渐渐死去 
哦 对不起 这句话打乱了时区
哦 你要我 在最爱的时候睡去
我越想越清醒
哦 爱你没差 那一点时差
哦 你离开这一拳给的 太重
我的心找不到 换日线它在哪
我只能不停的飞 知道我将你挽回
爱你不怕 那一点时差
哦 就让我静静一个人 出发
你的心总有个经纬度会留下
我会回到你时间 跨越爱的时差 
*/
