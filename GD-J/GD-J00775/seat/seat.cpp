#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	cin>>a[i];
	int t=a[1];
	sort(a+1,a+n*m+1,cmp);
	int k;
	for(k=1;k<=n*m;k++)
	if(a[k]==t) break;
	int c=k/n+(k%n!=0);
	int r=0;
	if(k%n==0)
	{
		if((k/n)%2==0)
		{
			r=1;
		}
		else
		{
			r=n;
		}
	}
	else
	{
		if((k/n)%2==0)
		{
			r=k%n;
		}
		else
		{
			r=n-(k%n)+1;
			if(r>n) r-=n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}

