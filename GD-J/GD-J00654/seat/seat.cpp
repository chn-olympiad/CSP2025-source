#include<iostream>
#include<cstdio>
#include<algorithm> 
using namespace std;
bool down(long long z,long long r)
{
	if(z>r)return 1;
	return 0;
}
long long n,m,a[105],wz;
int main()
{
	freopen("seat.in",r,stdin);
	freopen("seat.out",w,stdout);
	cin>>n>>m;
	long long x,ni,mi;
	cin>>x;
	a[1]=x;
	for(long long i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+(n*m+1),down);
	for(long long i=1;i<=n*m;i++)
	{
		if(a[i]==x)
		{
			wz=i;
			break;
		}
	}
	mi=wz/n+1;
	ni=wz%n;
	if(ni==0)
	{
		mi-=1;
		ni=n;
	}
	if((mi)%2==1)
	{
		cout<<mi<<" "<<ni;
	}
	else
	{
		cout<<mi<<" "<<(n-ni+1);
		
	}

	return 0;	
} 
