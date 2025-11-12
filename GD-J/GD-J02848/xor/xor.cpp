#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h> 
using namespace std;
int a[1000010],c[10010];
int b[1010][1010];
int n,k;
int ans=0;
void dfs(int step,int num)
{
	if (step==n+1)
	{
		ans=max(ans,num);
		return;
	}
	for (int i=step;i<=n;i++)
	{
		int x=step,y=i;
		if (b[x][y])
		{
			dfs(y+1,num+1);
		}
	}
	dfs(step+1,num);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		int x=a[i];
		if (x==k)
		{
			b[i][i]=1;
			//cout<<i<<" "<<i<<endl;
		}
		for (int j=i+1;j<=n;j++)
		{
			x=x^a[j];
			
			if (x==k)
			{
				b[i][j]=1;
				//cout<<i<<" "<<j<<endl;
			}
			//cout<<i<<" "<<j<<" "<<x<<endl;
		}
	}
	dfs(1,0);
	cout<<ans;
	return 0;
 } 
