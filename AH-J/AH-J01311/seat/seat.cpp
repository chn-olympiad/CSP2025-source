#include<bits/stdc++.h>
using namespace std;
struct node{
	int mark;
	int originalnum;
	int seatx,seaty;
}a[1005];
bool cmp(node x,node y)
{
	return x.mark>y.mark;
}
int n,m,num,markx,marky;
bool direction;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	num=n*m;
	for(int i=1;i<=num;i++)
	{
		a[i].originalnum=i;
		cin>>a[i].mark;
	}
	sort(a+1,a+num+1,cmp);
	markx=1,marky=1;
	direction=true;
	for(int i=1;i<=num;i++)
	{
		a[i].seatx=markx;
		a[i].seaty=marky;
		if(a[i].originalnum==1)
		{
			cout<<a[i].seaty<<" ";
			cout<<a[i].seatx;
			return 0;
		}
		if(direction==true)
			markx++;
		else
			markx--;
		if(markx==n+1&&(marky+1)%2==0)
		{
			marky++;
			direction=false;
			markx--;
		}
		if(markx==0&&(marky+1)%2==1)
		{
			marky++;
			direction=true;
			markx++;
		}
	}
	return 0;
}
