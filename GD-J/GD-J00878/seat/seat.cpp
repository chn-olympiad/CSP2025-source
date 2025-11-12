#include<bits/stdc++.h>
using namespace std;
int a[10010];
int cmp1(int q,int p)
{
	return q>p;
 } 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,o=0;
	cin>>n>>m;
	o=n*m;
	for(int i=1;i<=o;i++)
	{
		cin>>a[i]; 
	}
	int p=a[1];
	sort(a+1,a+o+1,cmp1);
	for(int i=1;i<=o;i++)
	{
		if(a[i]==p)
		{
			p=i;
			break;
		}
	}
	int ma=(p%n),mb=(p/n)+1;
	if(ma==0)
	{
		ma=n;
		mb--;
	}
	if(mb%2==0) ma=n-ma+1;
	cout<<mb<<' '<<ma;
	return 0;
 } 
