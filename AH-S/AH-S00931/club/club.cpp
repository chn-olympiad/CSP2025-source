#include<bits/stdc++.h>
using namespace std;
int t,n,maxn;
int a[100010],b[100010],c[100010];
void dfs(int k,int ans,int s1,int s2,int s3)
{
	if(k==n+1)
	{
		if(ans>maxn)
		{
			maxn=ans;
		}
		return;
	}
	if(s1<n/2) dfs(k+1,ans+a[k],s1+1,s2,s3);
	if(s2<n/2) dfs(k+1,ans+b[k],s1,s2+1,s3);
	if(s3<n/2) dfs(k+1,ans+c[k],s1,s2,s3+1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		maxn=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		dfs(1,0,0,0,0);
		cout<<maxn<<endl;
	}
	return 0;
}
