#include<bits/stdc++.h>
using namespace std;

short n,m,i,x,y=1,a1,a[101];

bool cmp(short a,short b)
{
	return a>b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m>>a1;
	for(i=1;i<=n*m-1;i++)
		cin>>a[i];
	a[n*m]=a1;
	sort(a+1,a+n*m+1,cmp);
	for(i=1;i<=n*m;i++)
	{
		if(y%2==1){//单数列
			if(x==n)y++;
			else x++;
		}
		else{//双数列
			if(x==1)y++;
			else x--;
		}
		if(a[i]==a1){
			cout<<y<<' '<<x;
		}
	}
	
	return 0;
}
