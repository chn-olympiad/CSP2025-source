#include<bits/stdc++.h>
using namespace std;
int n,m,top;
struct Node{
	int i,f;
}a[110];
bool cmp(Node x,Node y)
{
	return x.f>y.f;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].f;
		a[i].i=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
			for(int j=1;j<=n;j++)
				if(a[++top].i==1) cout<<i<<" "<<j;
		else
			for(int j=n;j>=1;j--)
				if(a[++top].i==1) cout<<i<<" "<<j;
	}
	return 0;
}
