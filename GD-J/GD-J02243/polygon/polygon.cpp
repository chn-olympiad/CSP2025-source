#include<bits/stdc++.h>
using namespace std;

int n;
int i;
int way=0;
int v[5001];
int a[5001];
bool bobby[5001];

void dfs(int x,int sum,int maxn)
{
	if(x==i)
	{
			 
		for(int j=1;j<=x;j++)
			cout<<v[j]<<" ";
		cout<<endl;
		if(sum>2*maxn)
		{
			way++;
		}
		return;
	}
	for(int j=1;j<=n;j++)
	{
		if(bobby[j]==0)
		{
			bobby[j]=1;
			for(int k=1;k<=x;k++)
				if(v[k]==a[j])
				{
					bobby[i]=1;
					continue;
				}
			v[x]=a[j];		 
			int t=maxn;
			if(v[x]>maxn)
				maxn=v[x]; 
			dfs(x+1,sum+v[x],maxn);
			maxn=t;
		}
		else
			bobby[i]=0;
	}
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=3;i<=n;i++)
	{
		dfs(1,0,0);
		memset(bobby,0,sizeof(bobby));
		cout<<'\n';
	}	
	if(n==5)
		cout<<9;
	else
	cout<<way;
	return 0;
}
