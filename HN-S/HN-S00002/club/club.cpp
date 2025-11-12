#include<bits/stdc++.h>
using namespace std;
int t,n,maxs=-99999;
int stu[2005][5];
int tim[5];
void dfs(int x,int y,int s)
{
	tim[y]--;
	if(x>=n)
	{
		//比较ans
		//cout<<endl;
		maxs=max(maxs,s);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(tim[i]>0)
		{
			//cout<<stu[x+1][i]<<" ";
			dfs(x+1,i,s+stu[x+1][i]);
			tim[i]++;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		tim[1]=n/2;tim[2]=n/2;tim[3]=n/2;
		for(int j=1;j<=n;j++)
			cin>>stu[j][1]>>stu[j][2]>>stu[j][3];
		for(int j=1;j<=3;j++)
		{
			//cout<<stu[1][j]<<" ";
			dfs(1,j,stu[1][j]);//第一个数字表示当前搜索的第几个人，j表示这个人选哪一个。
			tim[j]++;
		}
		cout<<maxs<<endl;
		maxs=-99999;
	}
	return 0;
}
