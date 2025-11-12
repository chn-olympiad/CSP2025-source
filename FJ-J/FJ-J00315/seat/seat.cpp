#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v;
long long x;
long long xiaor;
bool cmp(int x,int y)
{
	return x>y;
}
int i;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n+5][m+5];
	memset(a,-1,sizeof(a));
	while(cin>>x)
	{
		v.push_back(x);
	}
	xiaor = v.front();
	sort(v.begin(),v.end(),cmp);
	for(int j = 1;j<=n;j++)
	{
		if(j%2==1){
			for(int k = 1;k<=m;k++)
			{
				a[j][k] = v[i];
				i++;
			}
		}
		else if(j%2==0)
		{
			for(int z = m;z>=1;z--)
			{
				a[j][z] = v[i];
				i++;
			}
		}
	}
	for(int j = 1;j<=n;j++)
	{
		for(int k = 1;k<=m;k++)
		{
			if(a[j][k] == xiaor)
			{
				cout<<j<<" "<<k;
				return 0;
			}
		}
	}
	return 0;
 } 
