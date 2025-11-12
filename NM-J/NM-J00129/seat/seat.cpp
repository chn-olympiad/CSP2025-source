#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100100],b[100100];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	   cin>>a[i];
	int l=a[1];
    sort(a+1,a+n*m+1);	
	for(int i=1;i<=n*m;i++)
	    b[i]=a[n*m-i]+1;
	b[n*m]=a[1];

	for(int i=1;i<=n*m;i++) 
	    if(b[i]==l) {l=i;}
	if(l<=n) {cout<<1<<" "<<l;return 0;}
	if(m%2!=0) 
	{
	for(int i=3;i<=m;i+=2)
	    for(int j=1;j<=n;j++)
	        if(((i-1)*n)+j==l) {cout<<i<<" "<<j<<endl;}
	for(int i=2;i<=m-1;i+=2)
	    for(int j=n;j>=1;j--)
	        if((i*n)-(n-j+1)==l) {cout<<i<<" "<<j<<endl;}
	}
	    else if(m%2==0)
		{
		 for(int i=3;i<=m-1;i+=2)
	        for(int j=1;j<=n;j++)
	           if(((i-1)*n)+j==l) {cout<<i<<" "<<j<<endl;}
		 for(int i=2;i<=m;i+=2)
	               for(int j=n;j>=1;j--)
	                   if((i*n)-(n-j+1)==l) {cout<<i<<" "<<j<<endl;}
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
