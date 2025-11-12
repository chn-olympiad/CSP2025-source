#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],len;
int pos;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	len=n*m;
	for(int i=1;i<=len;i++)cin>>a[i];
	int R=a[1];
	sort(a+1,a+len+1,cmp);
	for(int i=1;i<=len;i++)
	{	
		if(a[i]==R)
		{
			pos=i;break;
		}
	}
	int y;
	if(pos%n==0)y=pos/n;
	else y=pos/n+1;
	int maxx=y*n;
	int cha=maxx-pos;
	if(y%2==0)
	{
		cout<<y<<" "<<(cha+1);
	}
	else
	{
		cout<<y<<" "<<(n-cha);
	}
	return 0;
}	
