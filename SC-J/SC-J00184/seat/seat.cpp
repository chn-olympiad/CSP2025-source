#include<bits/stdc++.h>
using namespace std;
int n,m,a,s[105],b,c,d;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>s[i];
	a=s[1];
	sort(s+1,s+1+m*n);
	for(int i=1;i<=n*m;i++)
		if(s[n*m-i+1]==a)b=i;
	c=(b-1)/n+1;
	if(c%2==0)d=(b%n==0)?1:n-b%n+1;
	else d=(b%n==0)?n:b%n;
	cout<<c<<' '<<d;
	return 0;
}