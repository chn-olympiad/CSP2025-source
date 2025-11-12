#include <bits/stdc++.h>
using namespace std;
int value[100005][4];
int n,t;
int cmax = 0;
void dfs(int who,int a,int b,int c,int sum)
{
	if(who == n+1)
	{
		cmax = max(cmax,sum);
		return;
	}
	if(a < n/2)dfs(who+1,a+1,b,c,sum+value[who][1]);
	if(b < n/2)dfs(who+1,a,b+1,c,sum+value[who][2]);
	if(c < n/2)dfs(who+1,a,b,c+1,sum+value[who][3]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i = 1;i<=t;i++)
	{
		cin>>n;
		cmax = 0;
		for(int j = 1;j<=n;j++)
		{
			cin>>value[j][1]>>value[j][2]>>value[j][3];
		}
		dfs(1,0,0,0,0);
		cout<<cmax<<endl;
	}
	return 0;
} 
//Ren5Jie4Di4Ling5%
