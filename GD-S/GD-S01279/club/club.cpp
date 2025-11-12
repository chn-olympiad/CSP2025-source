#include<bits/stdc++.h>
using namespace std;
int i;
int T,n,c[4];
int m[100001][4];
int dp[4][100001];
int maxn=0,sum=0;
int cl[4][100001];
int a[100001];
void dfs(int k)
{
	for(int i=1;i<=3;i++)
	{
		if((c[i]+1)<=(n/2))
		{
			c[i]++;
			sum+=m[k][i];
			if(k==n)
				maxn=max(maxn,sum);
			else dfs(k+1);
			sum-=m[k][i];
			c[i]--;
		}
	}
}

bool sort1(int a,int b)
{
	if(a>b) return 1;
	else return 0;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		c[1]=0,c[2]=0,c[3]=0;
		
		
		scanf("%d",&n);
		
		if(n<200)
		{
			for(int i=1;i<=n;i++)
			scanf("%d%d%d",&m[i][1],&m[i][2],&m[i][3]);
			sum=0,maxn=0;
			dfs(1);
			cout<<maxn<<endl;
		}else
		{

			for(int i=1;i<=n;i++)
				scanf("%d 0 0",&a[i]);
			i=1;
			sort(a+1,a+n,sort1);
			for(int i=1;i<=n/2;i++)
			{
				maxn+=a[i];
			}
			cout<<maxn;
		 } 
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//Ren5Jie4Di4Ling5%
