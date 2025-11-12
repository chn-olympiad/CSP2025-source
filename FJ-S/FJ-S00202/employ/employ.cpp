#include<iostream>
#include<algorithm>
using namespace std;
int n,m,s[505],c[505],p[505],cnt;
long long ans=0;
const long long mod=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%1d",&s[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)
		p[i]=i;
	if(n<=10)
	{
		do
		{
			cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(cnt>=c[p[i]]||!s[i])
					cnt++;
			}
			if(n-cnt>=m)
			{
				ans++;
				ans%=mod;
			}			
		}while(next_permutation(p+1,p+n+1));
		printf("%lld\n",ans); 
		return 0;
	}
	return 0;
}
/*
T2 不会
东凑西凑 100+12+10+8=130
最后半小时了，已经绝望了 
拼尽全力还没去年挂飞后的高（去年220->140） 
初赛 J87 S92时我还以为我的OI有救了
上午J 380 时我更自信了
我在J的代码中写：If I can go to DT and continue OI,I will biaobai 
然后梦就碎了 
三年OI终是一场梦 
至少我曾经辉煌过 
R.I.P
yinbe(luogu uid:759152):2022-7-22~2025-11-01
goodbye,OI 
*/
