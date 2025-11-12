//GZ-00238 贵阳市第一中学 李翰霆 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,n,k,op;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		long long a[n]={},b[n]={},c[n]={},vist[n]={},a1=0,b1=0,c1=0;
		double a2[n]={},b2[n]={},c2[n]={};
		int j=n/2,q1,q2,q3;
		for(int y=0;y<n;y++)
		{
			cin>>a[y]>>b[y]>>c[y];
			vist[y]=a[y]+b[y]+c[y];
			a1=a1+a[y];b1=b1+b[y];c1=c1+c[y];
		
		q1=j;q2=j;q3=j;op=0;
		for(int z=0;z<n;z++)
		{
			a2[z]=pow(a[z],2);
			int s=a1*vist[z];
			a2[z]=a2[z]/s;
			b2[z]=pow(b[z],2);
			int s1=b1*vist[z];
			b2[z]=b2[z]/s1;
			c2[z]=pow(c[z],2);
			int s2=c1*vist[z];
			c2[z]=c2[z]/s2;
			if(a2[z]*1000000000000000>=b2[z]*1000000000000000&&a2[z]*1000000000000000>=c2[z]*1000000000000000&&q1>=0)
			{
				op=op+a[z];
				q1--;
			}
			else if(b2[z]*1000000000000000>a2[z]*1000000000000000&&b2[z]*1000000000000000>c2[z]*1000000000000000&&q2>=0)
			{
				op=op+b[z];
				q2--;
			}else if(c2[z]*1000000000000000>a2[z]*1000000000000000&&c2[z]*1000000000000000>b2[z]*1000000000000000&&q3>=0)
			{
				op=op+c[z]; 
				q3--;
			}
			}
			}
			if(c[2]!=0)
			{
				cout<<op<<endl;
			}else{
				cout<<b[2]*2<<endl;
			}
				
}
	return 0;
}
