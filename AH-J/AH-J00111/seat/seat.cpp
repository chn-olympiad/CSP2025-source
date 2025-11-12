#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,bigger=1,b,x,y;
	cin>>n>>m;
	cin>>a;
	for(int i=2;i<=n*m;i++)
	{
	cin>>b;
	if(b>a)bigger++;
}
x=(bigger+n-1)/n;
y=(bigger-1)%n;
if(x%2==0)
y=n-y;
else y++;
cout<<x<<" "<<y;
		return 0;
}
