#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int N=100011;
int T;
int n;
int a[N][4];
int f[N][4];
int ans;
void dfs(int t,int num,int c1,int c2,int c3)
{
	if(t>n) ans=max(num,ans);
	if(c1<n/2) dfs(t+1,num+a[t][1],c1+1,c2,c3);
	if(c2<n/2) dfs(t+1,num+a[t][2],c1,c2+1,c3);
	if(c3<n/2) dfs(t+1,num+a[t][3],c1,c2,c3+1);
}
void init()
{
	memset(a,0,sizeof(a));
	memset(f,0,sizeof(f));
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		init();ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				scanf("%d",&a[i][j]);
		if(n<100000)		
			dfs(1,0,0,0,0);
		else
			for(int i=1;i<=n;i++)
				ans=ans+max(a[i][1],max(a[i][2],a[i][3]));
		cout<<ans<<endl;
	}
	return 0;
}
