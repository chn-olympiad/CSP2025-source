#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r;
	cin>>n>>m;
	int a[110],b;
	for(int i=1;i<=n*m;i++)
	  cin>>b>>a[i];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    for(int k=1;k<=n*m;k++)
	      if(b>a[k+1] && b<a[i])
	      {
	        c=i;
	        r=j;
	      }
	cout<<c<<" "<<r;
	return 0;
}
