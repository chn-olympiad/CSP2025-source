#include <bits/stdc++.h>
using namespace std;
int n,m;
int map1[105];
int xiaoR;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++)
	{
		cin>>map1[i];
	}
	xiaoR = map1[1];
	sort(map1+1,map1+n*m+1,cmp);
	int f = 0;
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=m;j++)
		{
			f+=1; 
			if(xiaoR == map1[f]) 
			{
				if(i%2 == 0)
				{
					cout<<i<<" "<<n-j+1;
				}else
				{
					cout<<i<<" "<<j;
				} 
				return 0;
			}
		}
	}
	return 0;
}
