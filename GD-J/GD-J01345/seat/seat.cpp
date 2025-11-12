#include<bits/stdc++.h>
using namespace std;
int n,m,k,w,c,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>k;
	for(int i=2,t;i<=n*m;i++)
	{
		cin>>t;
		if(k<t)
			w++;	
	}
	c=w/n+1;
	if(c%2)
		r=1+w%n;
	else r=n-w%n;
	cout<<c<<" "<<r<<endl;
	return 0;
} 
