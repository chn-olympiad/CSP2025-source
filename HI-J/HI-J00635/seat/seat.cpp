#include<bits/stdc++.h>
using namespace std;
int a[200];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,xr,yr,k;
	cin>>n>>m;
	cin>>a[1];
	int N=n*m;
	k=1;
	for(int i=2;i<=N;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])
		k++;
	}
	if(k%n==0) xr=k/n;
	else xr=k/n+1;
	yr=k-(xr-1)*n;
	if(xr%2==0) yr=n-yr+1;
	cout<<xr<<" "<<yr; 
	return 0;
}
