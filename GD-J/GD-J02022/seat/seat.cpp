#include<bits/stdc++.h>
using namespace std;
int n,m,a[10015],d,c;
bool cmp(int a,int b)
{
	return a>b?true:false;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	d=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==d)
		c=i;
	}
	if(c%n==0)
	{
		if((c/n)%2==1)
		cout<<c/n<<" "<<n;
		else
		cout<<c/n<<" "<<1;
		
	}
	else
	{
		if((c/n+1)%2==1)
		cout<<c/n+1<<" "<<c%n;
		else
		cout<<c/n+1<<" "<<n-c%n+1; 
	}
	return 0;
}
