#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m;
struct up{
	int s,b;
}a[N];
bool cmp(up a,up b)
{
	return a.s>b.s;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int u=n*m;
	a[1].b=1;
	for(int i=1;i<=u;i++)
	{
		cin>>a[i].s;
	}
	sort(a+1,a+1+u,cmp);
	int x=1,y=1,z=1;
	for(int i=1;i<=u;i++)
	{
		if(i!=1)
		{
			if(z==1&&x==n)
			y++,z=-1;
			else if(z==-1&&x==1)
			y++,z=1;
			else
			x+=z;
		}
		if(a[i].b==1)
		{
			cout<<y<<" "<<x<<endl;
			break;
		}
	}
	return 0;
}
