#include<bits/stdc++.h>
using namespace std;
int m,n,x,s=0;
int a[105];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m*n;i++)
	{
		cin>>a[i];
		if(a[i]>=a[0]){s++;}
	}
	x=(s+n-1)/n;
	cout<<x<<' ';
	if(x%2){cout<<s-n*(x-1);}
	else{cout<<n*x-s+1;}
	return 0;
}