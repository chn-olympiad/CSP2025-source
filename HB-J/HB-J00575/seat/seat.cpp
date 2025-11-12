#include<bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t;
	cin>>n>>m;
	for(int i=2;i<=n*m;i++)
		cin>>a[i];
	sort(a+2,a+n*m+1);
	for(int i=1;i<=n*m;i++)
		if(a[1]>a[i]&&a[1]<a[i+1])
			t=i;
	if(a[1]<a[2])
		t=1;
	if(a[1]>a[n*m])
		t=n*m;
	int f=ceil(double((n*m-t)%n));
	cout<<f<<" ";
	if(f%2==1)
		cout<<(n*m-t+1)%n+n;
	if(f%2==0)
	{
		cout<<n-(n*m-t+1)%n;
	}
	return 0;
}

