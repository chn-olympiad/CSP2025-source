#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[1010],d=1,h=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])d++;
	}
	while(d>n)
	{
		d-=n;
		h++;
	}
	cout<<h<<" ";
	if(h%2==1)cout<<d;
	else cout<<n-d+1;
	return 0;
}
