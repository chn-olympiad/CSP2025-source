#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	int tgt=a[1];
	for(int i=2;i<=n*m;i++)
		cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	int pos;
	for(int i=1;i<=n*m;i++)
	{
		if(tgt==a[i])
		{
			pos=i;
			break;
		}
	}
	if(((pos+n-1)/n)%2==0)
	{
		cout<<(pos+n-1)/n<<" "<<n-pos%n+1;
	}
	else
	{
		cout<<(pos+n-1)/n<<" "<<(pos%n==0?n:pos%n);
	}
	return 0;
}
