#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],o,t,x,y; 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	o=a[1];
	sort(a+1,a+1+(n*m));
	for (int i=n*m;i>=1;i--)
	{
		t++;
		if (a[i]==o) break;
	}
	int w=t%m;
	if (w==0) w=m;
 	if (w==m) x=t/m;
	else x=t/m,x++;
	if (x%2==0) y=m-w+1;
	else y=w;
	cout<<x<<" "<<y;
	return 0;
}
