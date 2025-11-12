#include<bits/stdc++.h> 
using namespace std;
int a[1005][1005];
void node()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<t+n;
}
int main()
{ 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	whlie(t--) node();
	return 0;
}
