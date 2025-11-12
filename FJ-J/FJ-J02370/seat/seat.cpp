#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],o,wei,h,l;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	l=n*m;
	for(int i=0;i<l;i++)
	{
		cin>>a[i];
	}
	o=a[0];
	sort(a,a+l,cmp);
	for(int i=0;i<l;i++)
	{
		if(a[i]==o)
		{
			wei=i+1;
			break;
		}
	}
	h=(wei+n-1)/n;
	if(wei%n==0)
	cout<<h<<" "<<n;
	else if(h%2==0)
	{
		cout<<h<<" "<<n-wei%n+1;
	}
	else
	cout<<h<<" "<<wei%n;
	return 0;
}
