#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,c,r,cnt=1,a[110];
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1]) cnt++;
	}
	if(cnt%n==0) c=cnt/n;
	  else c=cnt/n+1;
	if(c%2==0)
	  if(cnt%n==0) r=1;
		else r=n-cnt%n+1;
	  else
	    if(cnt%n==0) r=n;
	      else r=cnt%n;
	cout<<c<<" "<<r<<endl;
	return 0;
}
