#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	int tmp=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		tmp=(tmp<<1)+(tmp<<3)+c-'0';
		c=getchar();
	}
	return tmp*f;
}
int n,k;
int a[1000001];
int sum[1000001];
int ans[1000001];
int cnt=1;
map<int,int> to;
vector<int> p[1000001];
int now[1000001];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]^a[i];
		if(to.count(sum[i])==0)
		{
			to[sum[i]]=cnt++;
			p[to[sum[i]]].push_back(i);
		}
		else
		{
			p[to[sum[i]]].push_back(i);
		}
	}
	cnt--;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k)
		{
			ans[i]=max(ans[i],ans[i-1]+1);
			continue;
		}
		int tar=0;
		for(int j=0;j<=20;j++)
		{
			if(k&(1<<j))
			{
				tar+=((1<<j)^((1<<j)&sum[i-1]));
			}
			else
			{
				tar+=((1<<j)&sum[i-1]);
			}
		}
		int tmp=to[tar];
		for(int j=now[tmp];j<p[tmp].size();j++)
		{
			if(p[tmp][j]<=i)
			{
				now[tmp]++;
				continue;
			}
			ans[p[tmp][j]]=max(ans[i-1]+1,ans[p[tmp][j]]);
		}
		ans[i]=max(ans[i],ans[i-1]);
	}
	cout<<ans[n]<<endl;
	return 0;
}
