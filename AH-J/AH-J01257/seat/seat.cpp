#include <bits/stdc++.h>
using namespace std;
int m,n,f,y;
int a[105];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	int num=n*m;
	for(int i=1;i<=num;i++)
	{
		cin>>a[i];
	}
	f=a[1];
	sort(a+1,a+num+1,cmp);
	for(int i=1;i<=num;i++)
	{
		if(a[i]==f)
		{
			f=i;
			break;
		}
	}
	int x=f;
	x--;
	x/=n;
	x++;
	if(x%2==1)
	{
		y=f%n;
		if(y==0)
			cout<<x<<" "<<n<<endl;
		else
			cout<<x<<" "<<y<<endl;
	}
	else
	{
		y=f%n;
		if(y==0)
			cout<<x<<" "<<"1"<<endl;
		else
			cout<<x<<" "<<n-y+1<<endl;
	}
	return 0;
}
