#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	int sum=0;
	cin>>t;
	int n=2;
	int a[10],b[10],c[10],d[10];
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(int i=0;i<t;i++)
	{
		for(int i=0;i<n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		d[0]=a[0]+b[1];
		d[1]=a[0]+c[1];
		d[2]=b[0]+a[1];
		d[3]=b[0]+c[1];
		d[4]=c[0]+a[1];
		d[5]=c[0]+b[1];
		for(int i=0;i<6;i++)
		{
			sum=max(sum,d[i]);
		}
		cout<<sum<<endl;
	}
	return 0;
}
