#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[5][100009];
int c[100009];
int b[5];
int n,u;
ll ans=-1;
void dfs(int num,ll l)
{
	
	if(num>n)
	{
		ans=max(ans,l);
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		b[i]++;
		if(b[i]>u)
		{
			b[i]--;
			continue;
		}
		l=l+a[i][num];
		//cout<<"["<<i<<":"<<b[i]<<"]"<<"\n";
		//cout<<num<<":"<<l<<"\n";
		dfs(num+1,l);
		l=l-a[i][num];
		b[i]--;
	}
	return ;
}
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			c[i]=a[1][i];
		}
		u=n/2;
		if(n>30)
		{
			sort(c+1,c+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans=ans+c[i];
			}
			cout<<ans;
		}
		else
		{
			dfs(1,0);
			cout<<ans<<"\n";
		}
		
		ans=-1;
	}
	
		
	
	fclose(stdin);fclose(stdout);
	return 0;
}
