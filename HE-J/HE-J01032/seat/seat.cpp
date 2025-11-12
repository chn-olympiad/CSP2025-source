#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b=1,c=1,r=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])
		{
			b++;
		}
	}
	if(n==1&&m>1)	c=b;
	else if(m==1&&n>1)	r=b; 
	else if(m>1&&n>1)
	{
		if(b%n==0) c=b/n;
		else c=b/n+1;
		n*=2;
		if(b%n==0) r=1;
		else if(b%n>n/2) r=n-(b%n)+1;
		else r=b%n;	
	}
	cout<<c<<" "<<r; 
	fclose(stdin);
	fclose(stdout);
	return 0; 	
}
