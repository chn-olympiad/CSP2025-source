#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
long long n,c[502],m;
string s;
long long sum=0;
bool f[502];
long long li[502];
void dfs(int lev)
{
	if(lev==n+1)
	{
		long long cz=0,lc=0;
		for(long long i=1;i<=n;i++)
		{
			if(cz>=c[li[i]])
			{
				cz++;
				continue;
			}
			else
			{
				if(s[i-1]=='1') lc++;
				else cz++;
			}
			
		}
		if(lc>=m) sum++;
		return ;
	}
	for(long long i=1;i<=n;i++)
	{
		if(f[i]==0)
		{
			f[i]=1;
			li[lev]=i;
			dfs(lev+1);
			f[i]=0;
		}
	}
	return ;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(long long i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<sum;
	return 0;
}
