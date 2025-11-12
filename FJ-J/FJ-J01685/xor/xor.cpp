#include<bits/stdc++.h>
using namespace std;
int a[500010],s[500010],dy[500010],mn[500010];
vector<int> f[1048580];
int yh(int aaa,int bbb)
{
	return (aaa|bbb)-(aaa&bbb);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=yh(s[i-1],a[i]);
		if(!f[s[i]].size())
		{
			f[s[i]].push_back(0);
			f[s[i]].push_back(2);
		}
		f[s[i]].push_back(i);
		f[s[i]][0]++;
	}
	for(int i=1;i<=n;i++)
	{
		int t=yh(s[i-1],k);
		if(!f[t].size())
		{
			continue;
		}
		if(!f[t][0])
		{
			continue;
		}
		while(f[t][f[t][1]]<i&&f[t][1]<=f[t][0]+2)
		{
			f[t][1]++;
		}
		if(f[t][f[t][1]]<i)
		{
			f[t][0]=0;
			continue;
		}
		dy[i]=f[t][f[t][1]];
	}
	if(dy[n]==n)
	{
		mn[n]=n;
	}
	else
	{
		mn[n]=n+1;
	}
	for(int i=n-1;i;i--)
	{
		if(dy[i]<mn[i+1]&&dy[i])
		{
			mn[i]=dy[i];
		}
		else
		{
			mn[i]=mn[i+1];
		}
	}
	int ans=0;
	for(int i=1;i<=n;)
	{
		if(mn[i]==n+1)
		{
			break;
		}
		else
		{
			ans++;
			i=mn[i]+1;
		}
	}
	printf("%d",ans);
	return 0;
}
