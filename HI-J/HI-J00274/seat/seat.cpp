#include<bits/stdc++.h>
using namespace std;
long long n,m,a=1,b=-1,c,x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++)
	{
		cin>>c;
		if(b==-1)b=c;
		else if(c>b)a++;
	}
	if(a%n!=0)x++;
	x+=a/n;
	y=x%2==0? m-a%n+1:a%n;
	cout<<x<<" "<<y; 
	return 0;
}
