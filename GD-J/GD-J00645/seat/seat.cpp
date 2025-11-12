#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000];
int p,o;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==p) 
		{
			o=n*m-i+1;
			break;
		}
	}
	if(o%n==0) cout<<o/n<<" ";
	else cout<<o/n+1<<" ";
	if(o/n%2!=0) 
	{
		if(o%n!=0) cout<<o%n;
		else cout<<n;
	}
	else 
	{
		if(o%n==0) cout<<1;
		else cout<<n-o%n-1;
	}
	return 0;
} 
/*
	
	*/
