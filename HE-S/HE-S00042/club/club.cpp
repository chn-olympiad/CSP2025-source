#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N][4];
int n;
long long dfs(int x,int c1,int c2,int c3)
{
	if(x>n)
	{
		return 0;
	}
	long long res=0;
	for(int i=1;i<=3;i++)
	{
		if((i==1)&&((c1+1)<=(n/2)))
		{
			res=max(res,dfs(x+1,c1+1,c2,c3)+a[x][1]);
		}
		if((i==2)&&((c2+1)<=(n/2)))
		{
			res=max(res,dfs(x+1,c1,c2+1,c3)+a[x][2]);
		}
		if((i==3)&&((c3+1)<=(n/2)))
		{
			res=max(res,dfs(x+1,c1,c2,c3+1)+a[x][3]);
		}
	}
	return res;
}
int aa[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=0;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		cout<<dfs(1,0,0,0)<<"\n";	
		
	}
	return 0;
}
