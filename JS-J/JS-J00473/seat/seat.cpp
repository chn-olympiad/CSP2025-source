#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[105],id,pts,x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	pts=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
		if(pts==a[i])
		{
			id=n*m-i+1;
			break;
		}
	y=(id-1)/n+1,x=(id-1)%n+1;
	if(y&1)
        cout<<y<<" "<<x;
    else
        cout<<y<<" "<<n-x+1;
	return 0;
}
