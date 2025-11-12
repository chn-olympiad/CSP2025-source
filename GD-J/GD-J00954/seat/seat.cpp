#include<bits/stdc++.h>
using namespace std;
int n,m;
struct qq{
	int x;
	bool f;
}a[105];
bool cmp(qq x,qq y){return x.x>y.x;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].x;
	}
	a[1].f=1;
	sort(a+1,a+n*m+1,cmp);
	int p=0;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].f) p=i;
	}
	int l=(p-1)/n+1,h=0;
	if(l%2)
	{
		h=p-((l-1)*n);
	}
	else
	{
		h=(n-(p-((l-1)*n)))+1;
	}
	cout<<l<<" "<<h;
}
