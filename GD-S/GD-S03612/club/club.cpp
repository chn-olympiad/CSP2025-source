#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int c[100005];
int dp[100005][5][5][5];
int aans;
int dfs(int k,int A,int B,int C,int m,int n)
{
	aans=max(aans,m);
	if(k>n)
	{
		return m;
	}
	int ans=0;
	if(A+1<=n/2) ans+=dfs(k+1,A+1,B,C,m+a[k],n); 
	if(B+1<=n/2) ans+=dfs(k+1,A,B+1,C,m+b[k],n);
	if(C+1<=n/2) ans+=dfs(k+1,A,B,C+1,m+c[k],n);
	return m;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		aans=-1e9;
		cout<<dfs(1,0,0,0,0,n)+aans<<"\n";
	}
	return 0;	
} 
