#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[111],R,w;
int p,q;
void erfen()
{
	for(int i=1;i<=n*m;i++)
	{
		if(R==a[i])
		{
			w=i;
			return ;
		}
	}
}
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	erfen();
	if(w%n==0)p=w/n;
	else p=w/n+1;
	if(p==1)q=w;
	else if(p%2==1)
	{
		q=w%n;
	}
	else q=n-w%n+1;
	cout<<p<<" "<<q;
}
/*
2 2
98 99 100 97
*/
