#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,b1=0,b2=0,b3=0;
long long ans=0;
struct dd{int a1,a2,a3,d12,d21,d13,d31,d23,d32,b;}a[100010];
bool cmd12(dd x,dd y)
{
	return x.d12<y.d12;
}
bool cmd21(dd x,dd y)
{
	return x.d21<y.d21;
}
bool cmd13(dd x,dd y)
{
	return x.d13<y.d13;
}
bool cmd31(dd x,dd y)
{
	return x.d31<y.d31;
}
bool cmd23(dd x,dd y)
{
	return x.d23<y.d23;
}
bool cmd32(dd x,dd y)
{
	return x.d32<y.d32;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			a[i].a1>=a[i].a2?a[i].d12=a[i].a1-a[i].a2:a[i].d12=0x7ffffff1;
			a[i].a2>=a[i].a1?a[i].d21=a[i].a2-a[i].a1:a[i].d21=0x7ffffff1;
			a[i].a1>=a[i].a3?a[i].d13=a[i].a1-a[i].a3:a[i].d13=0x7ffffff1;
			a[i].a3>=a[i].a1?a[i].d31=a[i].a3-a[i].a1:a[i].d31=0x7ffffff1;
			a[i].a2>=a[i].a3?a[i].d23=a[i].a2-a[i].a3:a[i].d23=0x7ffffff1;
			a[i].a3>=a[i].a2?a[i].d32=a[i].a3-a[i].a2:a[i].d32=0x7ffffff1;
			if(a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3)b1++,a[i].b=1;
			if(a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3)b2++,a[i].b=2;
			if(a[i].a3>=a[i].a1&&a[i].a3>=a[i].a2)b3++,a[i].b=3;
		}
		while(b1>n/2)
		{
			sort(a+1,a+n+1,cmd12);
			int d12=a[1].d12;
			sort(a+1,a+n+1,cmd13);
			int d13=a[1].d13;
			if(d12>=d13)a[1].b=3,b1--,b3++;
			else
			{
				sort(a+1,a+n+1,cmd12);
				a[1].b=2,b1--,b2++;
			}
			a[1].d12=0x7ffffff7,a[1].d13=0x7ffffff7;
		}
		while(b2>n/2)
		{
			sort(a+1,a+n+1,cmd21);
			int d21=a[1].d21;
			sort(a+1,a+n+1,cmd23);
			int d23=a[1].d23;
			if(d21>=d23)a[1].b=3,b2--,b3++;
			else
			{
				sort(a+1,a+n+1,cmd21);
				a[1].b=1,b2--,b1++;
			}
			a[1].d21=0x7ffffff7,a[1].d23=0x7ffffff7;
		}
		while(b3>n/2)
		{
			sort(a+1,a+n+1,cmd31);
			int d31=a[1].d31;
			sort(a+1,a+n+1,cmd32);
			int d32=a[1].d32;
			if(d31>=d32)a[1].b=2,b3--,b2++;
			else
			{
				sort(a+1,a+n+1,cmd31);
				a[1].b=1,b3--,b1++;
			}
			a[1].d31=0x7ffffff7,a[1].d32=0x7ffffff7;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i].b==1)ans+=a[i].a1;
			else if(a[i].b==2)ans+=a[i].a2;
			else ans+=a[i].a3;
		}
		cout<<ans<<endl;
		ans=0,b1=0,b2=0,b3=0;
	}
	return 0;
}
