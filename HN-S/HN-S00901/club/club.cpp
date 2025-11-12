#include<bits/stdc++.h>
using namespace std;
const int N=2e2+5;
//struct node
//{
//	int num,id,f;
//}a[3*N];
//int s[5],b[5][N];
//map<int,int>m,m1;
//bool comp(node a1,node a2)
//{
//	return a1.num>a2.num;
//}
int a[N],b[N],c[N],dp[N][N][N],n;
int dfs(int x,int s1,int s2)
{
	if (x>n)
		return 0;
	if (dp[x][s1][s2])
		return dp[x][s1][s2];
	if (s1+1<=n/2)
		dp[x][s1][s2]=max(dp[x][s1][s2],dfs(x+1,s1+1,s2)+a[x]);
	if (s2+1<=n/2)
		dp[x][s1][s2]=max(dp[x][s1][s2],dfs(x+1,s1,s2+1)+b[x]);
	if ((x-s1-s2)+1<=n/2)
		dp[x][s1][s2]=max(dp[x][s1][s2],dfs(x+1,s1,s2)+c[x]);
	return dp[x][s1][s2];
}
void solve()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		cin>>a[i]>>b[i]>>c[i];
	for (int i=0;i<=n;++i)
		for (int j=0;j<=n;++j)
			for (int k=0;k<=n;++k)
				dp[i][j][k]=0;
	cout<<dfs(1,0,0)<<"\n";
//	int tmp=0;
//	m=m1;
//	s[1]=s[2]=s[3]=0;
//	for (int i=1;i<=n;++i)
//		cin>>a[++tmp].num>>a[++tmp].num>>a[++tmp].num,
//		a[tmp].id=a[tmp-1].id=a[tmp-2].id=i,
//		a[tmp].f=3,a[tmp-1].f=2,a[tmp-2].f=1;
//	sort(a+1,a+3*n+1,comp);
//	int ans=0;
//	for (int i=1;i<=3*n;++i)
//	{
//		if (s[a[i].f]==n/2)
//			continue;
//		//ans+=a[i].num;
//		b[a[i].f][++s[a[i].f]]=a[i].num;
//		//m[a[i].id]=s[a[i].f];
//	}
//	for (int i=1;i<=n/2;++i)
//	{
//		cin>>a[i]>>b[i]>>c[i];
//		dp[i][0]=dp[i][1]=dp[i][2]=
//		max({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
//		dp[i][0]+=a[i],
//		dp[i][1]+=b[i],
//		dp[i][2]+=c[i];
//	}
//	cout<<ans<<"\n"; 
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for (;t--;)
		solve();
	return 0;
}
