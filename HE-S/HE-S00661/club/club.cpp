#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int a[MAXN][4],p[4];
int maxn,sum;
void dfs(int x,int l)
{
	if(x==l+1)
	{
		maxn=max(sum,maxn);
		return;
	}
	for(int j=1;j<=3;j++)
	{
		if(p[j]<l/2)
		{
			sum+=a[x][j];
			p[j]++;
			dfs(x+1,l);
			p[j]--;
			sum-=a[x][j];
		}
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		memset(p,0,sizeof(p));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		sum=0,maxn=0;
		dfs(1,n);
		cout<<maxn<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
