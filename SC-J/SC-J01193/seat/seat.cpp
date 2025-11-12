#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=110;
int n,m,a[N],x,id,h,l;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	x=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++)
		if(x==a[i])id=i;
//	cout<<id<<"\n";
	l=ceil(1.0*id/n);
	int it=id%n;
	if(it==0)it=n;
	if(l%2==1)h=it;
	else h=n-it+1;
	cout<<l<<" "<<h;
	return 0;
}
/*
2 2
99 100 97 98
*/