#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
long long n,m,a[501],sum=1,mod=998244353;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	bool flag=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')
		{
			flag=1;
			break;
		}
	}
	if(!flag||m==1)
	{
		for(int i=1;i<=n;i++)
		{
			sum*=i;
			sum%=mod;
		}
		cout<<sum;
		return 0;
	}
}
//额，现在是17点49分，我骗完了（？
//这些骗分看起来都很好想...也可能是我想简单了
//有点燃尽了，这个第一题真是心灵和肉体上的折磨...可能别的大佬10分钟以内就打完正解了但是我真是太废物了QAQ
//骗你的时间没这么长
//Raise a glass to freedom, something that you will never take away
//剩下30多分钟好像也不能干什么了=(
//look at where you are, look at where you started
//The fact that you're alive is a 完蛋了奇迹的英文怎么写
//miricle mirecle mericle maricle miracle！
//谢谢输入法终于试出来力=)
//Just stay alive, that would be enough
//石头说我和hwh在一起不会超过10年
//但在此之前至少也有9年（？
//石头在考场外面等我，但她的朋友我忘记带着一起来了，对不起=( 
