#include <bits/stdc++.h>//Íê³É 
using namespace std;
int a[110]; 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+n*m+1);
//	for(int i=1;i<=n*m;i++)
//	cout<<a[i];
		int w;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==t)	{
		w=i;
					}
	}
	w=n*m+1-w;
//	cout<<w;
	int x,y;
	if(w%n==0)	y=w/n;
	else y=w/n+1;
	if(y%2==1&&w%n!=0)	x=w%n;
	else if(y%2==1&&w%n==0)	x=n;
	else if(y%2==0)	x=n+1-w%n;
	cout<<y<<" "<<x;
	return 0;
}
// 2 2 99 100 98 97
// 2 2 98 100 99 97
//3 3 94 95 96 97 98 99 100 93 92
