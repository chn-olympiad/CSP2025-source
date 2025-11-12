#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],a1,t;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	a1=a[1];
	sort(a,a+n*m+1,cmp);
	for(int i=0;i<n*m;i++)
		if(a[i]==a1)
			t=i+1;
	if(t%n==0)
	{
		if(t/n%2) cout<<t/n<<' '<<n;
		else cout<<t/n<<' '<<1;
	}
	else
	{
		if(t/n%2) cout<<t/n+1<<' '<<n-t%n+1;
		else cout<<t/n+1<<' '<<t%n;
	}
	return 0;
}
