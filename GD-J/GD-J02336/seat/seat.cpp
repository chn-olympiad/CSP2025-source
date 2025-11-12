#include<bits/stdc++.h>
using namespace std;

int n,m;

int st[11][11];
int cun;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;//n为行，m为列
	int j=0;
	
	//输入处理 
	for(int i=1;i<=m;i++)//lie
	{
		if(i%2==0)
		{
			j--;
			for(;j>=1;j--)//hang
			{
				cin>>st[j][i];
			}
		}
		else
		{
			j++;
			for(;j<=n;j++)//hang
			{
				cin>>st[j][i];
			}
		}
	} 
	int ans=st[1][1];
	
	
	j=0;
	//判断 
	for(int i=1;i<=m;i++)//lie
	{
		if(i%2==0)
		{
			j--;
			for(;j>=1;j--)//hang
			{
				if(j==1 && st[j][i]<st[j][i+1])
				{
					cun=st[j][i];
					st[j][i]=st[j][i+1];
					st[j][i+1]=cun;
				}
				else if(st[j][i]<st[j-1][i])
				{
					cun=st[j-1][i];
					st[j-1][i]=st[j][i];
					st[j][i]=cun;
				}
			}
		}
		else
		{
			j++;
			for(;j<=n;j++)//hang
			{
				if(j==n && st[j][i]<st[j][i+1])
				{
					cun=st[j][i];
					st[j][i]=st[j][i+1];
					st[j][i+1]=cun;
				}
				else if(st[j][i]<st[j+1][i])
				{
					cun=st[j+1][i];
					st[j+1][i]=st[j][i];
					st[j][i]=cun;
				}
			}
		}
	} 

	//输出 
	int pan=0;
	for(int i=1;i<=m;i++)//lie
	{
		if(i%2==0)
		{
			j--;
			for(;j>=1;j--)//hang
			{
				if(st[j][i]==ans)
				{
					cout<<i<<" "<<j;
					pan=1;
					break;
				}
			}
		}
		else
		{
			for(;j<=n;j++)//hang
			{
				if(st[j][i]==ans)
				{
					cout<<i<<" "<<j;
					pan=1;
					break;
				}
			}
		}
		if(pan==1)
			break;
	} 
	return 0;
	
}
