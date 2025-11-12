#include<iostream>
using namespace std;
int a[10005];
int b[10005];
int c[10005];
int m[10005];
int main()
{
	//freopen(club.in,"r",stdin);
	//freopen(club.out,"w",stdout);
	int t;
	int n;
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		cin>>t;
		int d=0,e=0,f=0,z=0;
		for(int j=0;j<t;j++)
		{
			cin>>a[j]>>b[j]>>c[j];
			if(a[j]>=b[j]&&a[j]>c[j]&&d<t/2)
			{
				m[i]=a[j];
				d++;
			}
			else if(b[j]>=a[j]&&b[j]>c[j]&&e<t/2)
			{
				m[i]=b[j];
				e++;
			}
			else if(c[j]>=a[j]&&c[j]>b[j]&&f<t/2)
			{
				m[i]=c[j];
				f++;
			}
			z=z+m[i];
		}
		cout<<z<<endl;
	}
	
	return 0;
}
