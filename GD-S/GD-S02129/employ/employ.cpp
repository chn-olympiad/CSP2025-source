#include<bits/stdc++.h>
using namespace std;
long long n,m,c[1000005],k[1000005],l[1000005],ans;
string g;
void dfs(long long h,long long s)
{
	if(s==n+1)
	{
		long long fq=0,rq=0;
		for(int i=1;i<=n;i++)
		{
			if(fq>=l[i]||g[i]-'0'==0)
			{
				fq++;
				continue;
			}
			if(g[i]-'0'==1)rq++;
		}
		cout<<rq<<endl;
		for(int i=1;i<=n;i++)cout<<l[i]<<" ";
		if(rq>=m)
		{
			ans=(ans+1)%998244353;
		}
		cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(k[i]==1)continue;
		k[i]=1;
		l[s]=c[i];
		dfs(i,s+1);
		l[s]=0;
		k[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>g;
	g='U'+g; 
	bool flag=0;
	for(int i=1;i<=n;i++)
	if(g[i]=='0')flag=1;
	for(int i=1;i<=n;i++)
	cin>>c[i];
	if(flag==0)
	{
		long long p=1;
		for(int i=2;i<=n;i++)
		p=p*i%998244353;
		cout<<p;
	}
	else 
	{
		dfs(1,1);
		cout<<ans%998244353;
	}
	return 0;
}
