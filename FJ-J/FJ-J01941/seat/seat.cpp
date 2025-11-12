#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	int r,wr=1;
	cin>>r;
	for(int i=2;i<=n*m;i++)
	{
		int a;cin>>a;
		if(r<a)wr++;
	}
	int x=1,y=1;//x lie y hang
	x+=wr/(2*n)*2;
	wr=wr%(2*n);
	if(wr>n)
	{
		x+=1;
		wr-=n;
		y=n-wr+1;
	}
	else y=wr;
	cout<<x<<' '<<y;
	return 0;
}
