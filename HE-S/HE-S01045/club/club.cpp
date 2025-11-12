#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int t1=0;t1<t;t1++)
	{
		int n;
		cin>>n;
		int a[n+1][4],amax[n+1],ans=0;
		int maxa,mina;
		int bmax[4]={0};
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int l=1;l<n;l++)
				{
					maxa=max(a[l][i],a[l+1][i]);
					mina=min(a[l][i],a[l+1][i]);
					a[l][i]=maxa;a[l+1][i]=mina;
				}
			}
			for(int j=1;j<=n/2;j++)
			{
				bmax[i]=bmax[i]+a[j][i];
			}
		}
		cout<<max(max(bmax[1],bmax[2]),bmax[3])+min(min(bmax[1],bmax[2]),bmax[3]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
