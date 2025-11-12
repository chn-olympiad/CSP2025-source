#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[120],k,g;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x=n*m,y;
	for(int i=1;i<=x;i++) cin>>a[i];
	k=a[1];
	sort(a+1,a+x+1,cmp);
	for(int i=1;i<=x;i++)
	{
		if(a[i]==k)
		{
			g=i;
			i=10086;
			continue;
		}
	}
	x=g/n;
	y=g%n;
	if(y==0) y=n;
	else x+=1;
	if(x%2==0) y=n-y+1;
	cout<<x<<" "<<y<<endl;
	return 0;
}
