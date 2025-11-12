#include <bits/stdc++.h>
using namespace std;
const int N=105;
struct node
{
	int a,id;
}s[N];
bool cmp(node x,node y)
{
	return x.a>y.a;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int q=n*m;
	for(int i=1;i<=q;i++)
	{
		cin>>s[i].a;
		s[i].id=i;
	}
	sort(s+1,s+q+1,cmp);
	int p=0,k;
	for(int i=1;i<=q;i++)
	{
		if(s[i].id==1)
		{
			p=i;
		}
	}
	//cout<<p;
	if(p%n==0)k=p/n;
	else k=p/n+1;
	cout<<k<<" ";
	if(k%2==0)
	{
		int h=p%n;
		if(h==0)cout<<1;
		else cout<<n-h+1;
	}
	else
	{
		int h=p%n;
		if(h==0)cout<<n;
		else cout<<h;
	}
	return 0;
}
