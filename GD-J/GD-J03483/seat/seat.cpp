#include<bits/stdc++.h>
using namespace std;
int a[1000];
bool cmp(int a,int b)
{
	if(a>b)return 1;
	return 0;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,l,x;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	l=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=m*n;i++)if(a[i]==l)x=i;
	if(x/n%2==0)
	{
		if(x%n==0)cout<<x/n<<' '<<1;
		else cout<<x/n+1<<' '<<x%n;
	}
	else
	{
		if(x%n==0)cout<<x/n<<' '<<n;
		else cout<<x/n+1<<' '<<n-x%n+1;
	}
	return 0;
} 
