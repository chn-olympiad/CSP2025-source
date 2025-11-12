#include<bits/stdc++.h>
using namespace std;
int a[100010][4],n;
long long dfs(int n1,int a1,int b,int c)
{
	long long ma=0;
	if(n1>n) return 0;
	if(a1>=1) ma=max(ma,dfs(n1+1,a1-1,b,c)+a[n1][1]);
	if(b>=1) ma=max(ma,dfs(n1+1,a1,b-1,c)+a[n1][2]);
	if(c>=1) ma=max(ma,dfs(n1+1,a1,b,c-1)+a[n1][3]);
	return ma;
}
int main(  )
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		const int ma_g=n/2;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		cout<<dfs(1,ma_g,ma_g,ma_g)<<'\n';
	}
	return 0;
}
