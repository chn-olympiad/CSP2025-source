#include<bits/stdc++.h>
using namespace std;
int a[101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k,c,r,tmp,p;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	  cin>>a[i];
	k=a[1];
	for(int b=1;b<=n*m;b++)
	  for(int j=n*m;j>b;j--)
	  {
	  	if(a[j]>a[j-1])
	  	{
	  		tmp=a[j];
	  		a[j]=a[j-1];
	  		a[j-1]=tmp;
		}
	  }
	for(int l=1;l<=m*n;l++)
	  if(a[l]==k) {p=l;break;}
	c=ceil(1.0*p/n);
	if(c%2==1) 
	{
		r=p%n;
		if(r==0) r+=n;
	}
	else 
	{
		r=(n-p%n+1)%n;
		if(r==0) r+=n;
	}
	cout<<c<<" "<<r;
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}