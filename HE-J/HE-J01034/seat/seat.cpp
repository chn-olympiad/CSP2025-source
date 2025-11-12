#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000];
bool cmp(int a,int b) 
{
	return a>b;
}
int main()
{
	freopen("seat3.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int b=a[1],c;
	sort(a+1,a+(n*m+1),cmp);
	for(int i=1;i<=n*m;i++) 
	{
		if(a[i]==b) 
		{
			c=i;
			break;
		}
	}
	int z;
	if(c%n==0)  z=c/n;
	else z=(c+n)/n;//ÐÐÊý 
	cout<<z<<" ";
	if(z%2==1) 
	{
		if(c%n==0) cout<<n;
		else cout<<c%n;
	}
	else 
	{
		if(c%n==0) cout<<1;
		else cout<<n+1-(c%n);
	}
	return 0;
}
