#include<bits/stdc++.h>
using namespace std;
int t,z[10000],m[10000],bb2[10000],n,b1[10000],b2[10000],b3[10000],s[10000];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n=0,x=0,nn;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int	s=0,h=0,hh=0;
		cin>>n;
//		z[i]=n/2;
//		nn=n+nn;
		for(int j=1;j<=n;j++)
		{
			cin>>b1[j]>>b2[j]>>b3[j];
			if(b1[j]==0)
			{
				h++;
//				cout<<h<<"     ";
			}
				
			if(b3[j]==0)
			{
				hh++;
//				cout<<hh<<"       ";
			}
				
			bb2[j]=b2[j];
//			cout<<"       "<<b2[j]<<"         ";		
		}
//		cout<<n<<" "<<s<<endl;
		if(h==n&&hh==n)
		{
			for(int k=1;k<=n;k++)
			{
				for(int g=1;g<=n-i;g++)
					if(bb2[g]>bb2[g+1])
						swap(bb2[g],bb2[g+1]);
			}
			for(int k=n;k>n/2;k--)
			{
				s=s+bb2[k];
			}
			cout<<s<<endl;
		}
	}
	return 0;
}
