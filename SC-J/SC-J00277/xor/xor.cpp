#include<bits/stdc++.h>
using namespace std;
int n,k,sum,t1,t2,t,tot;
int a[1000050];
int t_1[1000050],t_2[1000050];
bool dfs(int x,int y) 
{
	int ans=0;
	for(int i=x;i<y;i++)
	{	
		if((a[i]==1&&a[i+1]==0)||(a[i]==0&&a[i+1]==1))
		{
			ans=1;
		}
		else
		{
			ans=0;
		}
		a[i+1]=ans;
	
	}
	if(ans==k)
	return true;
	else 
	return false;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	//int z=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(i==j)
			{
				if(k==a[i])
				{
					sum++;
					a[i]=-1;
					continue;	
				}
			}
			
			if(a[i]!=-1&&a[j]!=-1)
			{
				//cout<<"1";
				if(dfs(a[i],a[j]))
				{
					sum++;	
					for(int z=i;z<=j;z++)
					a[i]=-1;	
					//cout<<i<<" "<<j<<endl;
					continue ;
				}
			}
			
		}	
	}
	cout<<sum;
	return 0;
}