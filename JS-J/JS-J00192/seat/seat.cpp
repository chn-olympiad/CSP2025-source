#include<bits/stdc++.h>
using namespace std;
int n,m,a,b[105],pm=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>m>>pm;
    for(int i=1;i<=n*m-1;++i)
    {
		cin>>b[i];
		if(b[i]>a) pm++;
	}
	double v=pm*1.0/n;
	cout<<ceil(v)<<' ';
	if((pm/n)%2==1)
	{
		if(pm%n==0) cout<<n;
		else cout<<n+1-pm%n;
	}
	else
	{
		if(pm%n==0) cout<<1;
		else cout<<pm%n;
	}
	return 0;
}
