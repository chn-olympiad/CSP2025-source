#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105];
	int pr=1;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1]) pr++;
	}
	int m1=ceil(1.0*pr/n);
	int n1;
	if(m1%2==1) n1=pr%m;
	else n1=n-pr%m+1;
	if(n1==0)
	{
		if(m1%2==1) n1=n;
		else n1=1;
	}
	cout<<m1<<' '<<n1;
	return 0;
 } 
