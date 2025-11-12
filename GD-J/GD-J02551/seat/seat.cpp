#include<bits/stdc++.h>
using namespace std;
struct node{
	int s;
	int index;
}a[1000];
int n,m;
bool cmp(node b,node c)
{
	return b.s>c.s;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i].s;
		a[i].index=i; 
	}
	sort(a+1,a+k+1,cmp);
	int seat=0;
	for(int i=1;i<=k;i++)
	{
		if(a[i].index==1)
		{
			seat=i;
			break;
		}
	}
	int g=seat/n;
	int g1=g;
	if(g*n!=seat)g++;
	if(g%2!=0)
	{
		seat=seat-g1*n;
		if(seat==0)cout<<g<<" "<<n;
		else
		cout<<g<<" "<<seat;
	} 
	else
	if(g%2==0)
	{
		seat=seat-g1*n;
		if(seat==0)cout<<g<<" "<<1;
		else
		cout<<g<<" "<<n-seat+1;
	} 
	return 0;
}
