#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
long long n,ans;
long long a[5500];
bool if1;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) if1=true;
	}
	if(n<=2)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		int maxx=max(a[1],max(a[2],a[3]));
		int minn=min(a[1],min(a[2],a[3]));
		int midd=a[1]+a[2]+a[3]-maxx-minn;
		if(minn+midd>maxx) cout<<1;
		else cout<<0;
	}
	if(!if1)
	{
		int chushu=1,beichushu=0;
		for(int i=4;i<=n;i++)
			for(int j=4;j<=i;j++)
			{
				chushu=1;
				for(int k=j+1;k<=i;k++)
					if(k<=i-j+1) continue;
					else chushu=(chushu*k)%mod;
				for(int k=2;k<=min(j+1,i-j);k++)
					if(chushu%k!=0) chushu=chushu*mod/k;
					else chushu/=k;
				beichushu+=chushu;
			}
		cout<<beichushu;
	}
	return 0;
} 
/*
好难啊我都要哭了
CCF好心给个一等奖吧 ┭┮﹏ ┭┮ 
*/
