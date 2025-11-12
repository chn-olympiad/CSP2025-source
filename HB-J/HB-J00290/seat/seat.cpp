#include <bits/stdc++.h>
using namespace std;
int a[105],n,m,l;
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
    {
		cin>>a[i];
	}
	l=a[1];
	sort(a+1,a+n*m+1,cmp);
	int s;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==l)
		s=i;
	}
	if((s/n)%2==0)
	{
		if(s%n==0)
		cout<<s/n<<" "<<1;
		else cout<<s/n+1<<" "<<s%n;
	}
	else
	{
		if(s%n==0)
		cout<<s/n<<" "<<n;
		else cout<<s/n+1<<" "<<m-s%n+1;
	}
    return 0;
}
