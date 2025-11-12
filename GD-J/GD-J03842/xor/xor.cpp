#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
int n,k,a[510000],s[510000],f[510000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	map<int,int> mp;
	mp[0]=0;
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		if(mp.find(k^s[i])!=mp.end())
		{
			f[i]=max(f[i],f[mp[k^s[i]]]+1);
		}
		mp[s[i]]=i;
	}
	printf("%d\n",f[n]);
}

