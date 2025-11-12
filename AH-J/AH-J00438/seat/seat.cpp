#include <bits/stdc++.h>
using namespace std;
int a[200];
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,r,x,y;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=m*n;i++)
	{
		if(a[i]==r)
		{
			r=i;
			break;
		}
	}
	x=(r+n-1)/n;
	if(x%2==1) y=r-n*(x-1);
	else y=n-(r-n*(x-1)-1);
	cout<<x<<" "<<y;
	return 0;
}
