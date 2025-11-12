#include<bits/stdc++.h>
using namespace std;
int  main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int a[m][3];
	for(int i=0;i<m;i++)
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	for(int i=0;i<m;i++)
	{
		for(int j=i+1;j<m;j++)
		{
			if(a[i][2]>a[j][2])
				swap(a[i],a[j]);
			if(a[i][0]==a[j][0]&&a[i][1]==a[j][1])
			{
				swap(a[j],a[m]);
				m-=1;
			}
		}
	} 
	int sum=0;
	for(int i=0;i<(n-1);i++)
	{
		cout<<a[i][2]<<endl;
		sum+=a[i][2];
	}
	cout<<sum;
	return 0;
} 
