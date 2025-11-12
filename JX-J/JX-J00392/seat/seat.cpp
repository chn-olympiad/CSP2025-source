#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5000];
int a1;
int cnt;
int x,y;
int main() 
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1 ; i<=n*m ; i++)
	{
		cin>>a[i];
	}
	a1=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m ; i>0 ; i--)
	{
		cnt++;
		if(a[i]==a1) 
			break;
	}
	x=(cnt-1)/n+1;
	if(x%2!=0)
	{
		if(cnt%n==0) y=n;
		else y=cnt%n;
	} 
	else y=n+1-cnt%n;
	cout<<x<<' '<<y;
	return 0;
}
