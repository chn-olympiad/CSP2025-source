#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[5009];
long long b[5009];
long long ans;
void dfs(long long deep,long long maxx,long long sum)
{
	if(deep>n)
	{
		if(sum>maxx*2)
		{
			ans++;
			ans%=998244353;
		}
		return ;
	}
	dfs(deep+1,maxx,sum);
	dfs(deep+1,max(maxx,a[deep]),sum+a[deep]);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1,0,0); 
	cout<<ans;
	//CCF are sb!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//fuck ccf's mother£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡
	//ccf don't have 78 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
