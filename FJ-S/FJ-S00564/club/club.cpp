#include<bits/stdc++.h>
using namespace std;
int T,n,a[100+10][100+10],maxx,sum;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.ans","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		sum=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++) cin>>a[i][j];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++) maxx=max(maxx,a[i][j]);
			sum+=maxx;
			maxx=0;
		}
		cout<<sum<<endl;
	}
	return 0;
}
