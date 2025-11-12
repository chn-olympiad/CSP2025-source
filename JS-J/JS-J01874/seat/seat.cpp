#include<bits/stdc++.h>
using namespace std;
long long n,m,map[50][50],a[100005],b[100005],f;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	f=b[1];
	sort(b+1,b+1+n*m);
	for(int i=1;i<=n*m;i++)
	{
		a[i]=b[n*m+1-i];
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==f)
		{
			f=i;
		}
	}
	int x,y;
	x=f/n;
	if(f%n!=0)
	{
		x+=1;
	}
	if(x%2==0)
	{
		if(f%n==0)
		{
			y=1;
		}
		else
		{
			y=n-(f%n)+1;
		}
	}
	else
	{
		if(f%n==0)
		{
			y=n;
		}
		else
		{
			y=f%n;
		}
	}
	cout<<x<<" "<<y;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
