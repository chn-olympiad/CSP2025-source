#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,o[1000005],l[1000005],ans,ans1;
long long mid=998244353;
char f[1000005];
void dfs(int x,int y,int z)
{
	if(z==b)
	{
		ans=1;
		for(int i=1;i<=a-x+1;i++)
		{
			ans=ans%mid;
			ans=ans*i;
		}
		ans1+=ans%mid;
		ans1%=mid;
		return;
	}
	if(x>a)return;
	for(int i=1;i<=a;i++)
	{
		if(l[i]==0)
		{
			l[i]=1;
			if(o[i]<=y)
			{
				dfs(x+1,y+1,z);
			}
			else
			{
				if(f[x]=='0')
				{
					dfs(x+1,y+1,z);
				}
			else	dfs(x+1,y,z+1);
			}
			l[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>a>>b;
scanf("%s",f+1);
for(int i=1;i<=a;i++)
{
	cin>>o[i];
}
dfs(1,0,0);
cout<<ans1%mid;
	return 0;
}
