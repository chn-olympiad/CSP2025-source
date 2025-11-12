#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,c,a[100+10],p,x,y;
bool cmp(int x, int y)
{
  if(y!=x)
    return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>c;
	int ans=n*m-1;
	for(int i=1;i<=ans;i++)
	  cin>>a[i];
	sort(a+1,a+ans+1,cmp);
	for(int i=1;i<=ans;i++)
	  if(a[i]<c)
	  {
		p=i;
		break;
	  }
	if(p%m==0)
	{
	  y=p/m;
	  if(y%2!=0)
	    x=m;
	  else
	    x=1;
	}
	else
	{
	  y=p/m+1;
	  if(y%2!=0)
	    x=p%m;
	  else
	    x=m-p%m+1;
	}
	cout<<y<<" "<<x;
	return 0;
}
