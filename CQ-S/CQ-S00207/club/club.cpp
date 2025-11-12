#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,a[100005][4],b[100005][4],x=0,y=0,z=0;
		cin>>n;
		int N=n/2;
		for(int i=1;i<=n;i++)
		{
			int ma,mb;
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				b[i][j]=j;
			}
			for(int j=1;j<=3;j++)
			{
				for(int jj=j;jj<3;jj++) 
				if(a[i][jj]<a[i][jj+1])
				swap(b[i][jj],b[i][jj+1]);
			}
		}
		for(int i=1;i<=n;i++)
		for(int j=i;j<n;j++)
		if(a[j][b[j][1]]<a[j+1][b[j+1][1]])
		{
			swap(a[j][b[j][1]],a[j+1][b[j+1][1]]);
			swap(b[j][1],b[j+1][1]);
		}
		for(int i=1;i<=n;i++)
		{
			
		}
		
	}
	return 0;
}
