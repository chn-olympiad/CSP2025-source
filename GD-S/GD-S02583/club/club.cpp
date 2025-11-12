#include<iostream>
#include<stdio.h> 
using namespace std;
int a[1000010],b[1000010],c[1000010];
int ans=0;
int n;
void dfs(int step,int x,int y,int z,int sum)
{
	if (x>n/2||y>n/2||z>n/2) return;
	if (step==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	dfs(step+1,x+1,y,z,sum+a[step]);
	dfs(step+1,x,y+1,z,sum+b[step]);
	dfs(step+1,x,y,z+1,sum+c[step]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while (t--)
	{
		ans=0;
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
 } 
 //Ren5Jie4Di4Ling5%
