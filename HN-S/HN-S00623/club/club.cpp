#include<bits/stdc++.h>
using namespace std;
int T,n,ans=0;
const int N=1e5+5;
int a[N][4];
void dfs(int i,int num1,int num2,int sum)
{
	if(i==n+1)
	{
		if(num1>n/2||num2>n/2||num1+num2<n/2)	return;
		ans=max(ans,sum);
		return;
	}
	dfs(i+1,num1+1,num2,sum+a[i][1]);
	dfs(i+1,num1,num2+1,sum+a[i][2]);
	dfs(i+1,num1,num2,sum+a[i][3]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)	cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(n>=100)
		{
			for(int i=1;i<=n;i++)
			{
				ans+=max(a[i][1],max(a[i][2],a[i][3]));
			}
			printf("%d\n",ans);
			ans=0;
		}
		else
		{
			dfs(0,0,0,0);
			printf("%d\n",ans);
			ans=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
