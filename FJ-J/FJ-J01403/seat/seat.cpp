#include<bits/stdc++.h>
using namespace std;
int a[500];
int n,m;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	int w;
	for(int i=1;i<=n*m;i++) 
	{
		if(a[i]==x) w=i;
	}
	int l=ceil(1.0*w/n);
	cout<<l<<" ";
	if(l%2==0)
	{
		if(w%n==0) cout<<1;
		else cout<<n-(w%n)+1;
	}
	else
	{
		if(w%n==0) cout<<n;
		else cout<<w%n;
	}
}
