#include<bits/stdc++.h>
using namespace std;
struct Node{
	int a,b,c;
}a[100010];
int n,b[100010],ans;
void dfs(int x)
{
	if(x>n)
	{
		int club1=0,club2=0,club3=0,f=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i]==1) 
			{
				club1++;
				f+=a[i].a;
			}
			else if(b[i]==2) 
			{
				club2++;
				f+=a[i].b;
			}
			else 
			{
				club3++;
				f+=a[i].c;
			}
		}
		if(club1<=n/2&&club2<=n/2&&club3<=n/2&&f>ans) ans=f;
	}
	else
	{
		b[x]=1;
		dfs(x+1);
		b[x]=2;
		dfs(x+1);
		b[x]=3;
		dfs(x+1);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int nnnnn;
	cin>>nnnnn;
	while(nnnnn--)
	{
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
