#include<bits/stdc++.h>
using namespace std;
int n,m,a[10004],h=1,x,y=1,p;
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
	p=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(x==1&&h%2==0||x==n&&h%2==1)h++,y++;
		else
			if(h%2)x++;
			else x--;
		if(a[i]==p)break;
	}
	cout<<y<<" "<<x;
	return 0;
}
