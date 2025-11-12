#include<bits/stdc++.h>
using namespace std;
int n,m,c=0;
int a[10000];
int s;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
	cin>>a[i];	
	}
	int s=a[0];
	sort(a,a+n*m);
	int p=n*m-1;
	int r;
	while (s!=a[p])
	{
		p--;
	}
	p++;
	if(p%n!=0)
	{
	    c++;
		r=p%n; 
	}
	else
	{
		r=n;
	}
	cout<<c<<" ";
	if(c%2==0)
	{
		cout<<r; 
	}
	else
	{
		cout<<r+1;
	} 
	return 0;
}
