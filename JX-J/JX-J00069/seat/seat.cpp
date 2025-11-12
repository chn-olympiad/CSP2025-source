#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],x,cnt,c,b;
bool cmp(int x2,int y)
{
	return x2>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x)
		{
			cnt=i;
			break;
		}
	}
	c=int(cnt*1.0/n*1.0+0.9); 
	b=cnt%n;
	if(b==0) b=n;
	if(c%2==0) 
	{
		b=n-b+1;
	}
	cout<<c<<" "<<b<<endl;
	return 0;
}
