#include<bits/stdc++.h>
using namespace std;
int a[10001];
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
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+2,a+n*m+1,cmp);
	int t=n*m;
	for(int i=2;i<=n*m;i++)
	{
		if(a[1]>a[i])
		{
			t=i-1;
			break;
		}
	}
//	cout<<a[1]<<" "<<t<<endl;
	int x=t/n;
	if(t%n!=0)x++;
	int y;
	if(x%2==1)y=t%n;
	else y=n+1-t%n;
	if(y==0)y=n;
	cout<<x<<" "<<y;
	return 0;
}
