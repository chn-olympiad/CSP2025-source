#include<bits/stdc++.h>
using namespace std;
int n,m,s1,ans;
int a[500005],ma[500005],
s[500005],f[500005];
vector<int> c[1050005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=(s[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=ma[i-1];
		s1=(m^s[i]);
		if(a[i]==m)
		{
			f[i]=max(ma[i-1]+1,f[i]);
		}
		else
		{
			int lll=c[s1].size();
			for(int j=0;j<lll;j++)
			{
				f[i]=max(f[i],ma[c[s1][j]]+1);
			}
		}
		c[s[i]].push_back(i);
		if(s1==0)
		{
			f[i]=max(f[i],1);
		}
		ma[i]=max(f[i],ma[i-1]);
		ans=max(ans,f[i]);
	}
	printf("%d",ans);
	return 0;
}
