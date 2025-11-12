#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[1005];
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int t=a[1],k;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=m*n;i++)
	{
		if(a[i]==t) {k=(n*m)-i+1;break;}
	}
	if(k<=n) {cout<<"1 "<<k;return 0;}
	else
	{
		if(k%n==0)
		{
			int r=k/n;
			cout<<r<<" ";
			if(r%2==0) cout<<1;
			else cout<<n;
		}
		else
		{
			int s=k/n+1;
			cout<<s<<" ";
			if(s%2==0) cout<<n-k%n+1;
			else cout<<k%n;
		}	
	} 
	return 0;
}
