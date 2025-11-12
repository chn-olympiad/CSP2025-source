#include<bits/stdc++.h>
using namespace std;
int n,m,a[114514],cnt,x=1,y=1;
int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++)
{
	cin>>a[i];
	if(a[i]>a[1])
	cnt++;
}
//cout<<cnt<<endl;
for(int i=1;i<=cnt;i++)
{
	if(y%2==1)
	{
		if(x==n)
		y++;
		else
		x++;
	}
	else
	{
		if(x==1)
		y++;
		else
		x--;
	}
	//cout<<y<<' '<<x<<endl;
}
cout<<y<<' '<<x;
return 0;
}

