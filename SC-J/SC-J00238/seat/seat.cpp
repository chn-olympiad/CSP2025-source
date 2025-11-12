#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,cnt;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;cin>>a;
	for(int i=2;i<=n*m;i++)
	{
		cin>>b;
		if(b>a)cnt++;
	}
	cnt++;int l=(cnt+n-1)/n,h=(cnt-1)%n+1;
	if(!(l&1))h=n-h+1;
	cout<<l<<" "<<h;
	return 0;
}