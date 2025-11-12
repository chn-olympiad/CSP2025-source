#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,g;
struct W
{
	long long it,l;
}w[100005];
bool cmp(W x,W y)
{
	return x.l>y.l;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	c=a*b;
	for(int i=1;i<=c;i++)
	{
		cin>>w[i].l;
		w[i].it=i;
	}
	sort(w+1,w+c+1,cmp);
	g=1;
	e=1;
	for(int i=1;i<=c;i++)
	{
		d+=g;
if(d>a)
{
	e++;
	g=-1;
	d=a;
}
if(d==0)
{
	e++;
	g=1;
	d=1;
}
if(w[i].it==1)
{
	cout<<e<<" "<<d;
}
	}
	return 0;
}
