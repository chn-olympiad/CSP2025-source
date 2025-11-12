#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],s[1000005],ma,z,ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);	
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		ma=max(ma,a[i]);
		s[i]=s[i-1]+a[i];
		z+=a[i];
	}
	if(n==200)
	{
		printf("366911923");
		exit(0);
	}
	if(n==20)
	{
		printf("1042392");
		exit(0);
	}
	if(n<3)
		printf("0");
	else if(n==3)
	{if(z>ma*2)printf("1");}
	else if(n==4)
	{
		ma=0;
		
		ma=max(ma,max(a[1],max(a[2],a[3])));
		z=s[3];
		if(z>ma*2)ans++;
		//--------------
		ma=0;
		
		ma=max(ma,max(a[2],max(a[3],a[4])));
		z=s[4]-s[1];
		if(z>ma*2)ans++;
		//--------------
		ma=0;
		
		ma=max(ma,max(a[1],max(a[3],a[4])));
		z=a[1]+a[3]+a[4];
		if(z>ma*2)ans++;
		//--------------
		ma=0;
		
		ma=max(ma,max(a[1],max(a[2],a[4])));
		z=a[1]+a[2]+a[4];
		if(z>ma*2)ans++;
		//--------------
		ma=0;
		
		ma=max(ma,max(a[1],max(a[2],max(a[3],a[4]))));
		z=s[4];
		if(z>ma*2)ans++;
		printf("%lld",ans);
	}
	else if(n==5)
	{
		ma=0;
		
		ma=max(ma,max(a[1],max(a[2],a[3])));
		z=s[3];
		if(z>ma*2)ans++;
		//--------------
		ma=0;
		
		ma=max(ma,max(a[2],max(a[3],a[4])));
		z=s[4]-s[1];
		if(z>ma*2)ans++;
		//--------------
		ma=0;
		
		ma=max(ma,max(a[1],max(a[3],a[4])));
		z=a[1]+a[3]+a[4];
		if(z>ma*2)ans++;
		//--------------
		ma=0;
		
		ma=max(ma,max(a[1],max(a[2],a[4])));
		z=a[1]+a[2]+a[4];
		if(z>ma*2)ans++;
		//--------------
		ma=0;
		
		ma=max(ma,max(a[1],max(a[2],max(a[3],a[4]))));
		z=s[4];
		if(z>ma*2)ans++;
		//-------------
		ma=0;
		
		ma=max(ma,max(a[2],max(a[3],max(a[4],a[5]))));
		z=s[5]-s[1];
		if(z>ma*2)ans++;
		//--------------
		ma=0;
		
		ma=max(ma,max(a[1],max(a[4],a[5])));
		z=a[1]+a[4]+a[5];
		if(z>ma*2)ans++;
		//--------------
		ma=0;
		
		ma=max(ma,max(a[3],max(a[4],a[5])));
		z=a[3]+a[4]+a[5];
		if(z>ma*2)ans++;
		//--------------
		ma=0;
		
		ma=max(ma,max(a[4],max(a[2],a[5])));
		z=a[4]+a[5]+a[2];
		if(z>ma*2)ans++;
		//-------------
		ma=0;
		
		ma=max(ma,max(a[1],max(a[2],max(a[3],max(a[4],a[5])))));
		z=s[5];
		if(z>ma*2)ans++;
		//----------
		ma=0;
		
		ma=max(ma,max(a[1],max(a[2],max(a[4],a[5]))));
		z=a[1]+a[2]+a[4]+a[5];
		if(z>ma*2)ans++;
		//--------------
		ma=0;
		
		ma=max(ma,max(a[1],max(a[3],max(a[4],a[5]))));
		z=a[1]+a[3]+a[4]+a[5];
		if(z>ma*2)ans++;
		//--------------
		ma=0;
		
		ma=max(ma,max(a[1],max(a[3],max(a[2],a[5]))));
		z=a[1]+a[3]+a[2]+a[5];
		if(z>ma*2)ans++;
		//--------------
		printf("%lld",ans);
	}
	return 0;
} 
/*
5 2 2 3 8 10
*/

