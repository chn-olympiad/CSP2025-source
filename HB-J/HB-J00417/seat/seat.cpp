#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int r=a[1],mc;
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)
		if(a[i]==r)
			mc=n*m+1-i;
	cout<<(mc-1)/n+1<<" ";
	if(((mc-1)/n+1)%2!=0)
		cout<<(mc-1)%n+1;
	else
		cout<<n-(mc-1)%n;
	return 0;
}
