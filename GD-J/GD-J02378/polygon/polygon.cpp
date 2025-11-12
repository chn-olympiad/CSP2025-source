#include<bits/stdc++.h>
using namespace std;
long long n,a[50005],ans,b[5005],c[5005],l[5005];
map<string,int>m;
void dfs(long long k,long long s,long long h)
{
	if(s==k+1)
	{
		memset(l,0,sizeof(l));
		sort(c+1,c+k+1);
		long long sum=0;
		string p="";
		for(int i=1;i<=k;i++)
		{
			p=p+char(c[i]+'0');
			sum+=c[i];
		}
		if(m[p]==0&&sum>c[k]*2)
		ans++;
		m[p]=1;
		return ;
	}
	for(int i=h;i<=n;i++)
	{
		if(b[i]==1)continue;
		b[i]=1;
		c[s]=a[i];
		dfs(k,s+1,i);
		b[i]=0;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		memset(c,0,sizeof(c));
		memset(b,0,sizeof(b));
		c[0]=2e9;
		dfs(i,1,1);
	}
	cout<<ans%998244353;
	return 0;
}
