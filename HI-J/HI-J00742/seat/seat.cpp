#include <bits/stdc++.h>
using namespace std;
long long n,m,lin[10000],R,loc,x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>lin[i];
	R=lin[1];
	sort(lin+1,lin+1+n*m);
	for(int i=m*n;i>=1;i--) 	if(lin[i]==R) loc=i;
	loc=n*m-loc+1;
	if(n>0) x=loc/n,y=loc%n;
	if(y>0) x++;
	else y=n;
	if(x%2==0) y=n-y+1;
	cout<<x<<' '<<y;
	return 0;
} 
