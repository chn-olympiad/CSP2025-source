/*
	RP++!
	freopen!!!
*/
#include<bits/stdc++.h>
using namespace std;
int apts,pos,i=1,j=1,n,m;
int pts[110],a[110],s[20][20];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int k=1;k<=n*m;k++)
	{
		cin>>pts[k];
	}
	apts=pts[1];
	sort(pts+1,pts+n*m+1);
	for(int k=1;k<=n*m;k++)
	{
		a[k]=pts[n*m-k+1];
		if(a[k]==apts) pos=k;
	}
//	cout<<pos<<endl;
	if(pos%n!=0) j=pos/n+1;
	else j=pos/n;
	pos-=(j-1)*n;
	if(j%2==1) i=pos;
	else i=n-pos+1;
	cout<<j<<" "<<i;
	return 0;
}
