#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int n,m,a[maxn],x;
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
		x=a[1];
	}
	sort(a+1,a+1+n*m,cmp);
	int c;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x)
		{
			c=i;
			break;
		}
	}
	int l=c/n,h=c%n;
	if(l%2==1&&h!=0)
	{
		l+=1;
		h=n+1-h;
	}
	else if(l%2==1&&h==0)
	{
		h=n;
	}
	else if(l%2==0&&h!=0)
	{
		l+=1;
	}
	else if(l%2==0&&h==0)
	{
		h=1;
	}
	cout<<l<<" "<<h;
	return 0;
}