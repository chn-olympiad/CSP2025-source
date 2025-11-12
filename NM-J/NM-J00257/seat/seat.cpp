#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,numb=1,r,x,y;
	cin>>n>>m>>r;
	for(i=2;i<=n*m;i++)
	{
		int a;
		scanf("%d",&a);
		if(a>r) numb++;
	}
	y=(numb-1)/n+1;
	x=numb-(y-1)*n;
	if(y%2==0) x=m-x+1;
	cout<<y<<" "<<x;
	return 0;
}
