#include<iostream>
using namespace std;
int main()
{
	int n,t,a1=0,b1=0,c1=0;
	long a[100001],b[100001],c[100001],h=0;
	cin>>t>>n;
	for(int i=1;i<=t;i++)
	{
		h=0;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j]>>b[j]>>c[j];
		}
		for(int i=1;i<=n;i++)
		{
			if(a1<n/2 && b1<n/2 && c1<n/2)
			{
				if(a[i]>b[i] && a[i]>c[i]) 
				{
					a1++;
					h+=a[i];
				}
				if(b[i]>a[i] && b[i]>c[i]) 
				{
					b1++;
					h+=b[i];
				}
				if(c[i]>a[i] && c[i]>b[i])
				{
					c1++;
					h+=c[i];
				}
			}	
			else
			{
				if(a1>=n/2) h+=max(b[i],c[i]);
				if(b1>=n/2) h+=max(a[i],c[i]);
				if(c1>=n/2) h+=max(a[i],b[i]);
			}
		}
	    cout<<h;
	}
	
	return 0;
}
