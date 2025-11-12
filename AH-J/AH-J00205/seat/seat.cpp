#include<bits/stdc++.h>
using namespace std;
int n,m,x,IX;
int a[1001];
bool cmp(int x,int y)
{
	return x>y;
}
void work(int x)
{
	int l=(x-1)/n+1;
	cout<<l<<" ";
	if(l%2==1)
	{
		if(x-n*l==0)
			cout<<n<<endl;
		else
			cout<<x-n*(l-1)<<endl;
	}
	else
	{
		if(x-n*l==0)
			cout<<1<<endl;
		else
			cout<<n-(x-n*(l-1))+1<<endl;
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==x)
			IX=i;
	work(IX);
	return 0;
}
