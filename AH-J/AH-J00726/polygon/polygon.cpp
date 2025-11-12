#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans;
void dfs(int num,int i)
{
	if(num==n+1)
		return ;
	for(int j=i;n-j>=num-1;j++)
	{
		for(int k=1;k<=num;k++)
		{
			int s=a[j];
			int max=-1;
			for(int l=1;l<=num-1;l++)
			{
				s+=a[k+l+j];
				if(a[l+j]>max)
					max=a[k];
			}
			if(s>max*2)
				ans++;
		}
		dfs(num+1,j+1);
	}
	dfs(num+1,i+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(3,1);
	cout<<ans;
}
