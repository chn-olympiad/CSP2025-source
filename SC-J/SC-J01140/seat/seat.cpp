#include<bits/stdc++.h>
using namespace std;
const int N=0;
int n,m,a[105],a1,c,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a1;
	a[1]=a1;
	for(int i=2;i<=n*m;i++)
		cin>>a[i];
	sort(a+1,a+1+n*m);
	
	int w=m*n;
	while(a[w]!=a1)
		w--;
	w=m*n-w+1;
	
	if(w%n!=0)
		c=w/n+1;
	else
		c=w/n;
	w=w%n;
	if(w==0)
		w=n;
	if(c%2==1)
		r=w;
	else
		r=n-w+1;
	cout<<c<<" "<<r;
	
	
	return 0;
 } 