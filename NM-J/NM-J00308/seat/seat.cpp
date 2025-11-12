#include<bits/stdc++.h>
using namespace std;
long long a[110];
bool f=false,z=false;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","W",stdout);
	long long n,m,p,q,k=1,j=1;
	cin>>n>>m;
	p=n*m;
	for(int i=0;i<p;i++)
	{
		cin>>a[i];
	}
	q=a[0];
	sort(a,a+p);
	for(int i=p-1;i>=0;i--)
	{
		if((k==n||k==1)&&z)
		{
			j++;
		}
		z=false;
		if(a[i]==q)
		{
			cout<<j<<" "<<k;
			return 0;
		}
		if(!f) k++;
		else k--;
		if((k%n==1&&k!=1)||k==0)
		{
			f=!f;
			if(f) k=n;
			else k=1;
			z=true;
		}
	}
	return 0;
}
