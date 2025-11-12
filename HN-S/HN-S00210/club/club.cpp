#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int s;s<t;s++)
	{
		int d[3];
		int n;
		cin>>n;
		long long myd[10^10];
		for(long long i;i<=n;i++)
		{
			int a[n];
			int b[n];
			int c[n];
			cin>>a[i]>>b[i]>>c[i];
			if(c[i]>=b[i]>=a[i])
			{
				myd[i]=c[i];
				
			}
			else if(a[i]>=b[i]>=c[i])
			{
				myd[i]=a[i];
				
			}
			else if(a[i]>=c[i]>=b[i])
			{
				myd[i]=a[i];
			}
			else if(b[i]>=a[i]>=c[i])
			{
				myd[i]=b[i];
				
			}
			else if(b[i]>=c[i]>=a[i])
			{
				myd[i]=b[i];
				
			}
			else if(c[i]>=a[i]>=b[i])
			{
				myd[i]=c[i];
			}
			else if(c[i]=a[i]=b[i])
			{
				myd[i]=c[i];
				
			}
			else if(c[i]>a[i]==b[i])
			{
				myd[i]=c[i];
			
			}
			else if(a[i]=b[i]>c[i])
			{
				myd[i]=a[i];
			
			}
			else if(a[i]>b[i]==c[i])
			{
				myd[i]=a[i];
				
			}
			else if(b[i]>a[i]==c[i])
			{
				myd[i]=b[i];
				
			}
			else 
			{
				cout<<a[i]<<endl;
			}
		}
		int sdf=0;
		for(int asd;asd<=n;asd++)
		{
			sdf=sdf+myd[asd];
		}
		cout<<sdf<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
