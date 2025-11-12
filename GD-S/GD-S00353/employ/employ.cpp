#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+7,mod=998244353;
int n,m,ans=1;
int a[N];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int k=0,p=0;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0) k++;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(a[i]<k&&a[i+1]>=k) p=i;
		else ans*=(a[i]==0?1:i+1);
	}
	for(int i=n-p;i>=1;i--)
	{
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	return 0;
} 
/*
没有圆周的钟 失去旋转意义
下雨这天 好安静
远行没有目的 距离不是问题
不爱了 是你的谜底
我占据格林威治守候着你
在时间标准起点回忆过去
你却在永夜了的极地旅行
等爱在失温后渐渐死去
哦 对不起 这句话打乱了时区
哦 你要我 在最爱的时候睡去
我越想越清醒
哦 爱你没差 那一点时差
哦 你离开这一拳给的 太重
我的心找不到 换日线它在哪
我只能不停的飞 直到我将你挽回
哦 爱你不怕 那一点时差
哦 就让我静静一个人 出发
你的心总有个经纬度会留下
我会回到你世界 跨越爱的时差 
*/
