#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[1005];
bool cmp(int f,int l)
{
	return f>l; 
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
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1,op=1,lx=1;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==k)
		{
			cout<<y<<" "<<x;
			return 0;
		}
		if(x==n&&lx==0)
		{
			y++;
			op=-1;
			lx=1;
			continue;
		}
		if(x==1&&lx==0)
		{
			y++;
			op=1;
			lx=1;
			continue;
		}
		x+=op;
		lx=0;
	}
	return 0;
}
