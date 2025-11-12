#include<bits/stdc++.h> 
using namespace std;
int n,m,a[101],cnt=0;
int main ()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++) cin>>a[i];
	for (int i=2;i<=n*m;i++) if (a[i]>a[1]) cnt++;
	cnt++;
	int y=(cnt-1)/n+1,x;
	if (y%2==0) x=n-(cnt-1)%n;
	else x=(cnt-1)%n+1;
	cout<<y<<" "<<x;
	return 0;
} 
