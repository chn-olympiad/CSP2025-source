#include<bits/stdc++.h>
using namespace std;
int k;
int num[4];
int a[100005][4];
int maxn=0;
int n;
void dfs(int x,int num1)
{
	if(x==n+1)
	{
		maxn=max(maxn,num1);
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		num[i]++;
		if(num[i]<=k)
		{
			dfs(x+1,num1+a[x][i]);
		} 
		num[i]--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		maxn=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		k=n/2;
		dfs(1,0);
		cout<<maxn<<endl;
	}
	fclose(stdin);
	fclose(stdout);
 } 
 
