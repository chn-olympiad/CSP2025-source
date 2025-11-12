#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int a[N][5],n=0,ans=0,x[5];

void dfs(int c,int an)
{
	if(c>n)
	{
		ans=max(ans,an);
		return ;
	}
	
	for(int i=1;i<=3;i++)
	{
		if(x[i]>=n/2)
		{
			continue;
		}
		x[i]++;
		an+=a[c][i];
		dfs(c+1,an);
		an-=a[c][i]; 
		x[i]--;
	} 
	
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		
		dfs(1,0);
		
		cout<< ans <<endl;
	}
	
	return 0;	
} 
