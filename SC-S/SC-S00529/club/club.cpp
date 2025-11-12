#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int t;
int n;
int a[100010];
int f[100010][3];
int main(int argc, char** argv)
{
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int i=1;i<=3;i++)
				cin>>a[i];
		}
		int m=n/2;
		for(int i=1;i<=100010;i++)
			for(int j=1;j<=3;j++)
				f[i][j]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				f[i][j]=max(f[i][j],f[i-a[j]][j]+a[j]);
			}
		}
		cout<<f[n][1]+f[n][2]+f[n][3]<<endl;	
	}
	return 0;
}