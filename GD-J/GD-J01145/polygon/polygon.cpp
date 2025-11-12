#include<bits/stdc++.h>
using namespace std;
int b=0,c=0,d=0,num=0,n,e,f,a[1000005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<=1000000;i++)
	{
		if(a[i+1]>a[i])
		{
			e=a[i]; f=a[i+1];
			a[i]=f; a[i+1]=e;
		}
    }
	if(n<3){cout<<0;}
	else if(n=3){cout<<1;}
	else if(n=4)
	{
		if(a[0]+a[1]+a[2]>2*a[0]){num=num+1;}
		if(a[0]+a[1]+a[3]>2*a[0]){num=num+1;}
		if(a[0]+a[2]+a[3]>2*a[0]){num=num+1;}
		if(a[1]+a[2]+a[3]>2*a[0]){num=num+1;}
		if(a[0]+a[1]+a[2]+a[3]>2*a[0]){num=num+1;}
		cout<<num;
	}
		else if(n=4)
	{
		if(a[0]+a[1]+a[2]>2*a[0]){b=b+1;}
		if(a[0]+a[1]+a[3]>2*a[0]){b=b+1;}
		if(a[0]+a[2]+a[3]>2*a[0]){b=b+1;}
		if(a[1]+a[2]+a[3]>2*a[0]){b=b+1;}
		if(a[0]+a[1]+a[2]+a[3]>2*a[0]){b=b+1;}
		cout<<b;
	}

	
	return 0;
}
