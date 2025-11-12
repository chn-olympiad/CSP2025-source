#include<bits/stdc++.h>
using namespace std;
int a[100005][4],n;
long long ans=-1; 
void dfs(int s1,int s2,int s3,long long as)
{
	if(s1+s2+s3==n) 
	{
		if(as>ans) ans=as;
		return;
	}
	if(s1+1<=n/2) dfs(s1+1,s2,s3,as+a[s1+s2+s3+1][1]);
	if(s2+1<=n/2) dfs(s1,s2+1,s3,as+a[s1+s2+s3+1][2]);
	if(s3+1<=n/2) dfs(s1,s2,s3+1,as+a[s1+s2+s3+1][3]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=3;k++)
			{
				cin>>a[j][k];
			}
		}
		dfs(1,0,0,a[1][1]);
		dfs(0,1,0,a[1][2]);
		dfs(0,0,1,a[1][3]);
		cout<<ans<<endl;
		ans=-1;
	}
	return 0;
} 
