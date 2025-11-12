#include<bits/stdc++.h>
using namespace std;
int m,n,pm=1,xm,a,h,l;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>xm;
	for(int q=1;q<n*m;q++)
	{
		cin>>a;
		if(a>xm) pm++;
	}
	l=((pm-1)/n)+1;
	h=pm-(l-1)*n;
	if(l%2==0) h=n-h+1;
	cout<<l<<" "<<h;
	return 0;
 } 
