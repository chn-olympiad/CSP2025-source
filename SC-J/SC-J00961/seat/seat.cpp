#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define dow(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
const int N=105;
int n,m,k;
struct node
{
	int v,ip;
}a[N];
int c,r;
bool cmp(node x,node y) {return x.v>y.v;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	rep(i,1,n*m)
	{
		int j;
		cin>>j;
		a[i]={j,i};
	}
	sort(a+1,a+1+n*m,cmp);
	rep(i,1,n*m) if(a[i].ip==1) k=i;
	c=(k-1)/n+1;
	if(c%2) r=(k-1)%n+1;
	else r=n-((k-1)%n);
	cout<<c<<" "<<r;
	return 0;
}