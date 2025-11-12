#include<bits/stdc++.h>
using namespace std;
int goal[105],ans[102];
int main()
{
	int n,m,flag;
	cin>>n>>m;
	int zong=n*m;
	for(int i=1;i<=zong;i++)
		cin>>goal[i];
	int R=goal[1];
	sort(goal+1,goal+zong+1);
	for(int i=zong,k=1;i>=1;k++,i--)
		ans[i]=goal[k];
	for(int i=1;i<=n;i++)
	{
		for(int k=0;k<m;k++)
		{
			int u=k+1;
			if(ans[(i-1)*m+u]==R)
			{
				if(i%2==0)
				{
					cout<<i<<" "<<(m-k);
					return 0;
				}
				else
				{
					cout<<i<<' '<<(k+1);
					return 0;
				}
			}}}
	return 0;
}
