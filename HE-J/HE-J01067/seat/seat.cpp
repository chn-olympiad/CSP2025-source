#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],x=1,ansn,ansm;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<=m*n;i++)
	{
		x+=(int)(a[i]>a[1]);
	}
    ansm=(x%n==0?x/n:x/n+1);
    ansn=(x%n==0?n:(ansm%2==0?n-(x%n-1):x%n));
    cout<<ansm<<" "<<ansn;
	return 0;
}
