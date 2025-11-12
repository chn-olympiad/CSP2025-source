#include<bits/stdc++.h>
using namespace std;
int a[200];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,wz;
	cin>>n>>m;
	cin>>a[1];
	int pc=a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<n*m;j++)
	{
		for(int i=1;i<n*m;i++)
		{
			if(a[i]<a[i+1])
			{
				int temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==pc)
		{
			wz=i;
		}
	}
	int shang,yushu,c,r;
	shang=wz/n;
	yushu=wz%n;
	if(shang%2==0&&yushu!=0)
	{
		c=shang+1;
		r=yushu;
	}
	if(shang%2==0&&yushu==0)
	{
		c=shang;
		r=1;
	}
	if(shang%2!=0&&yushu!=0)
	{
		c=shang+1;
		r=n-yushu+1;
	}
	if(shang%2!=0&&yushu==0)
	{
		c=shang;
		r=n;
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
