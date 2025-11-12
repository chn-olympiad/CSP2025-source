#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100001][4],z,sum=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	while(t--)
	{
		sum=0;
		cin>>n;
		z=n/2;
		int maxn=0;
		for(int i=1;i<=n;i++)
		{
			maxn=0; 
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(a[i][j]>maxn) maxn=a[i][j];
			}
			a[i][0]=maxn;
			sum+=maxn;
		}
		cout<<sum<<endl;
	}
	return 0; 
}
