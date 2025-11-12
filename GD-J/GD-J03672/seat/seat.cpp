#include<bits/stdc++.h>
using namespace std;
long long a[225],n,m,x,y;
bool cmp(int x,int y)
{
	return x>y;
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
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x) 
		{	
			y=i;
			break;
		}
	}
	if((y/n)%2==0 && y%n!=0) cout<<(y/n)+1<<" "<<(y%n);
	else if((y/n)%2==0 && y%n==0) cout<<(y/n)<<" "<<1;
	else if((y/n)%2==1 && y%n!=0) cout<<(y/n)+1<<" "<<n+1-(y%n);
	else if((y/n)%2==1 && y%n==0) cout<<y/n<<" "<<n;
	return 0;
}
