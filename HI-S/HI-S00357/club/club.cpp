#include<bits/stdc++.h>
using namespace std;
int n,ans;
const int N=1e5+10;
struct node{
	int a[3];
}stu[N];
void dfs(int now,int x,int y,int z,int k)
{
	if(k==n)
	{
		ans=max(ans,now);
//		cout<<now;
	}
	if(x<n/2)
	dfs(now+stu[k].a[0],x+1,y,z,k+1);
	if(y<n/2)
	dfs(now+stu[k].a[1],x,y+1,z,k+1);
	if(z<n/2)
	dfs(now+stu[k].a[2],x,y,z+1,k+1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>stu[i].a[j];
			}
		}
		dfs(0,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
