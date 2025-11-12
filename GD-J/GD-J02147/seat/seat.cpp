#include<bits/stdc++.h>
using namespace std;
int a[10000];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)
	{
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+n*m+1,cmp);
	/*for(int i=1;i<=n*m;++i)
	{
		cerr<<a[i]<<' ';
	}*/
	int p=find(a+1,a+n*m+1,t)-a;
	int x=p/n+1,y=p%n;
//	cerr<<x<<' '<<y<<' '<<p<<endl;
	if(y==0)
	{
		x--;
		y=n;
	}
	if(x%2==1)
	{
		cout<<x<<' '<<y<<endl;
	}
	else
	{
		cout<<x<<' '<<n-y+1<<endl;
	}
	return 0;
}

