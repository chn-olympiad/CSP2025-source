#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[105];
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,num=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		num+=(a[i]>a[1]);
	}
	int flag=1,x=1,y=1;
	while(num)
	{
		x+=flag;
		num--;
		if(x==n+1||x==0) x-=flag,y++,flag=-flag;
	}
	cout<<y<<" "<<x;
	return 0;
}
