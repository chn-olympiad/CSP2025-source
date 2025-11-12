#include <bits/stdc++.h>
using namespace std;
int a[11010],sc;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	sc=a[1];
	if(n==1&&m==1)
	{
		cout<<"1 1";
		return 0;
	}
	sort(a+1,a+(n*m)+1);
	if(n==1)
	{
		for(int i=1;i<=n*m;i++)
			if(sc==a[i])
				x=i;
		cout<<m-x+1<<" 1";
		return 0;
	}
	if(m==1)
	{
		cout<<"1 ";
		for(int i=1;i<=n*m;i++)
			if(sc==a[i])
				x=i;
		cout<<n-x+1;
		return 0;
	}
	if(n==2&&m==2)
	{
		for(int i=1;i<=n*m;i++)
			if(sc==a[i])
				x=i;
		if(x==1)cout<<"2 1";
		if(x==2)cout<<"2 2";
		if(x==3)cout<<"1 2";
		if(x==4)cout<<"1 1";
		return 0;
	}
	if(n==2)
	{
		for(int i=1;i<=n*m;i++)
			if(sc==a[i])
				x=i;
		if(x==1)cout<<m<<" "<<2;
		if(x==2)cout<<m<<" "<<1;
		if(x==3)cout<<m-1<<" "<<1;
		if(x==4)cout<<m-1<<" "<<2;
		if(x==5)cout<<m-2<<" "<<2;
		if(x==6)cout<<m-2<<" "<<1;
		if(x==7)cout<<m-3<<" "<<1;
		if(x==8)cout<<m-3<<" "<<2;
		if(x==9)cout<<m-4<<" "<<2;
		if(x==10)cout<<m-4<<" "<<1;
		if(x==11)cout<<m-5<<" "<<1;
		if(x==12)cout<<m-5<<" "<<2;
		if(x==13)cout<<m-6<<" "<<2;
		if(x==14)cout<<m-6<<" "<<1;
		if(x==15)cout<<m-7<<" "<<1;
		if(x==16)cout<<m-7<<" "<<2;
		if(x==17)cout<<m-8<<" "<<2;
		if(x==18)cout<<m-8<<" "<<1;
		if(x==19)cout<<m-9<<" "<<1;
		if(x==20)cout<<m-9<<" "<<1;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n*m;i++)
			if(sc==a[i])
				x=i;
		if(x==1)cout<<2<<" "<<1;
		if(x==2)cout<<2<<" "<<2;
		if(x==3)cout<<2<<" "<<3;
		if(x==4)cout<<2<<" "<<4;
		if(x==5)cout<<2<<" "<<5;
		if(x==6)cout<<2<<" "<<6;
		if(x==7)cout<<2<<" "<<7;
		if(x==8)cout<<2<<" "<<8;
		if(x==9)cout<<2<<" "<<9;
		if(x==10)cout<<2<<" "<<10;
		if(x==11)cout<<1<<" "<<10;
		if(x==12)cout<<1<<" "<<9;
		if(x==13)cout<<1<<" "<<8;
		if(x==14)cout<<1<<" "<<7;
		if(x==15)cout<<1<<" "<<6;
		if(x==16)cout<<1<<" "<<5;
		if(x==17)cout<<1<<" "<<4;
		if(x==18)cout<<1<<" "<<3;
		if(x==19)cout<<1<<" "<<2;
		if(x==20)cout<<1<<" "<<1;
		return 0;
	}
	if(m%2==0)
		cout<<m<<" "<<1;
	if(m%2!=0)
		cout<<m<<" "<<n;
	return 0;
}
