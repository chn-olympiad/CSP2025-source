#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a,b,c,d;
	cin>>n>>m;
	cin>>a>>b>>c>>d;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a>b)
			{
				cout<<a;
			}
		}
	}
	cout<<n<<" "<<m;
	return 0;
}
