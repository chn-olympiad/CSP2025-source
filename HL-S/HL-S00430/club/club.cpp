#include<bits/stdc++.h> 
using namespace std;
int a[100010];
int b[100010];
int c[100010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		for(int j=0;j<n;j++)
		{
			cin>>a[j]>>b[j]>>c[j];
		}
		sort(a,a+n);
		int sum=0;
		for(int j=n/2;j<n;j++)
		{
			sum+=a[j];
		}
		cout<<sum<<endl;
		for(int j=0;j<n;j++)
		{
			a[j]=0;
			b[j]=0;
			c[j]=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 

