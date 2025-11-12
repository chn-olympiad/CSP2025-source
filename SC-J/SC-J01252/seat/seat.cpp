#include<bits/stdc++.h>
#define I ios::sync_with_stdio(0);
#define AK cin.tie(0);
#define CSP cout.tie(0);
using namespace std;
int n,m;
struct node
{
	int id,s;
}a[110];
int cmp(node a,node b)
{
	return a.s>b.s;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	I AK CSP
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) 
	{
		cin>>a[i].s;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int k,x,y;
	for(int i=1;i<=n*m;i++) 
	{
		if(a[i].id==1) 
		{
			k=i;
			break;
		}
	}
	x=(k-1)/n,y=k-n*x;
	if(x%2==1) y=n-y+1;
	cout<<x+1<<" "<<y;
	return 0;
}