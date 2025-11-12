#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int a[N];
int n,m,h;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	    cin>>a[i];
	for(int i=2;i<=n*m;i++)
	{
		if(a[i]>a[1])
		    h++;
	}
	h++;
	int a,b;
	if(h%n==0)
		a=h/n;
	if(h%n!=0)
	    a=h/n+1;
	if(a%2!=0)
	    b=h%n;
	if(a%2==0)
	    b=n-h%n+1;
	if(b==0)
	    b=h;
	cout<<a<<" "<<b;
	return 0;
}