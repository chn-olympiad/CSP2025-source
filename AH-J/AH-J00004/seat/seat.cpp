#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int N=110;
int n,m;
int a[N];

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int rm=a[1];
	
	sort(a+1,a+1+n*m,cmp);
	int rg=0;
	for(int i=1;i<=n*m;i++)
		if(a[i]==rm)
		{
			rg=i;
			break;
		}
		
	int x=0,y=(int)(ceil(rg*1.0/n));
	if(y%2==1)x=rg-(y-1)*n;
	else x=n-rg+(y-1)*n+1;
	
	cout<<y<<' '<<x;
	return 0;
}
