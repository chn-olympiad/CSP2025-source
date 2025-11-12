# include <bits/stdc++.h>
using namespace std;
int n,m,a[110],k,o,x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	k=a[1];

	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=n*m;j++)
	 {
	 	if(a[i]>a[j])
	 	{
	 		int t=a[i];
	 		a[i]=a[j];
	 		a[j]=t;
		 }
	 }
	}
	 
	for(int kk=1;kk<=n*m;kk++)
	if(a[kk]==k)
	{
		o=kk;
		break;
    }
	  if(o-o/n*n==0)
	  {
	  	x=o/n;
	  	y=n;
	  }
	  else
	  {
	  	x=o/n+1;
		y=o-(o/n*n);
	  	if(x%2==0)
	  	y=n-y+1;
	  }
	cout<<x<<" "<<y;
}