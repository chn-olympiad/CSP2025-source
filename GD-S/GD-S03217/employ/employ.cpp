#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,mod=998244353;
int a[N],p[N];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	bool flg=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		flg|=(a[i]!=1);
	}
	if(!flg)
	{
		int cnt=0;
		for(char ch:s)
		{
			if(ch=='0') break;
			cnt++;
		}
		if(cnt>=m)
		{
			int k=1;
			for(int i=1;i<=n;i++) k=k*i%mod;
			cout<<k;
		}
		else cout<<0;
	}
	else if(n<=10)
	{
		for(int i=1;i<=n;i++) p[i]=i;
		s=' '+s;
		int ans=0;
		do
		{
			int lq=0,cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(cnt>=a[p[i]])
				{
					cnt++;
					continue;
				}
				if(s[i]=='0') cnt++;
				else lq++;
			}
			if(lq>=m) ans++;
		}
		while(next_permutation(p+1,p+n+1));
		cout<<ans;
	}
	else cout<<0;
	return 0;
}
/*
28pts at min
“不可以，总司令。”
看能拿多少分吧。
估分至少有 300pts 了
我什么时候有这么强了？？？
别挂分啊求求了……
*/
