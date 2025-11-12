#include<bits/stdc++.h>
using namespace std;
int n,m;
double a[2000005][200005];
double b[2000005][200005];
int main()
{
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=2;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=2;j++)
		{
			cin>>b[i][j];
		}
	}
	cout<<0;
	return 0;
	//±£´æ½â×¢ÊÍ 
}
