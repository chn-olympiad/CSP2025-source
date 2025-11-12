#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("club.in","w",stdin);
	// freopen("club.out","r",stdout);
	int t;
	cin>>t;
	int a[10005][10];
	while(t--)
	{
		
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int xa,ya,za;
			cin>>xa>>ya>>za;
			a[i][1]=a[i][4]=xa;
			a[i][2]=a[i][5]=ya;
			a[i][3]=a[i][6]=za;
		}
		for(int i=0;i<=n;i++)
		{
			for(int j=1;j<=6;j++)
			{
				if(i==0||j==0)a[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=6;j++)
			{
				a[i][j]=max(a[i-1][j]+a[i][j],a[i][j-1]);
			}
		}
		cout<<a[n][6]<<endl;
	}
	return 0;
}
