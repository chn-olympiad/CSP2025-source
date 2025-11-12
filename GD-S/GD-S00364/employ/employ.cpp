#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
string s1;
long long a[100000];
long long vis[100000];
void dfs(long long j,long long p,long long sum)
{
	//cout<<j<<" "<<p<<" "<<sum<<'\n';
	if(j==n)return;
	if(sum>=m)ans++,ans%=998244353;
	for(long long i=1;i<=n;++i)
	{
		if(!vis[j])
		{
			if(s1[j]=='1')
			{
				if(p<a[i])
				{
					vis[i]=1;
					dfs(j+1,p,sum+1);
					vis[i]=0;
				}
				else{
					vis[i]=1;
					dfs(j+1,p+1,sum);
					vis[i]=0;
				}
			} 
			else
			{
				vis[i]=1;
				dfs(j+1,p+1,sum);
				vis[i]=0;
			}
		}
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s1;
	for(long long i=1;i<=n;++i)cin>>a[i];
	dfs(0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
