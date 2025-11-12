#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[510];
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=10)
	{
		int b[11],ans=0;
		for(int i=1;i<=n;i++)b[i]=i;
		do
		{
			int su=0;
			for(int i=1;i<=n;i++)
			{
				if(su>=a[b[i]])
				{
					su++;
					continue;
				}
				if(s[i-1]=='0')su++;
			}
			if(n-su>=m)ans++;
		}
		while(next_permutation(b+1,b+1+n));
		cout<<ans;
	}
	else if(n==m and s.find('0')!=-1)
	{
		cout<<0;
	}
	else if(s.find('0')==-1)
	{
		int su=0;
		for(int i=1;i<=n;i++)su+=(a[i]==0);
		if(n-su<m)
		{
			cout<<0;
			return 0;
		}
		int mod=998244353,ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%mod;
		cout<<ans;
	}
	else
	{
		cout<<"I AK CSP(假的";
	}
}
/*
最好情况 100+48+40+32=220pts，预计挂一堆。
我真的累了。
不知道说些什么。
我要走的路还很长。
17:19，已经极限了。
睡不着。
怎么办。
中午没吃饱。
希望有人能看见。
上午 J 耗费了大量的精力，不过好在似乎能 AK？
不清楚。
想睡觉。
想吃饭。
困。
即使跌倒，也不能就此败落。
赛后行为大赏见。
嘻嘻。
（我在干什么）
梦到啥说啥了属于是。
啊 啊 啊咦 啊咦 呃 啊 啊 哦 诶
哎 哦 哎 啊 诶 咦 呃 哎 哎哎哎↓ 哎哎↓
啊 啊 啊咦 啊咦 呃 啊 啊 哦 诶
唉 哦 诶啊诶咦 芜~ 呃 啊
具体忘了。
怎么才半点。
后面忘了。
~~睡觉。~~
*/
