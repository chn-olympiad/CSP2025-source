#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	char c;
	int sum=0,res=1;
	c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-')res=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		sum=(c-'0')+sum*10;
		c=getchar();
	}
	return sum*res;
}
void out(int sum)
{
	if(sum<0)
	{
		putchar('-');
		sum=-sum;
	}
	if(sum<10)
	{
		putchar(sum+'0');
	}
	else
	{
		out(sum/10);
		putchar(sum%10+'0');
	}
}
void wenjian()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
}
int a[1008617];
int n,m;
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	wenjian();
    n=read(),m=read();
    for(int i=1;i<=n*m;i++)a[i]=read();
    int res=a[1];
    sort(a+1,a+1+n*m,cmp);
    int x=1,y=0,lie=0;//x:lie y:hang
    for(int i=1;i<=n*m;i++)
    {
    	if(lie%2==0)y++;
    	else y--;
    	if(y>n&&lie%2==0)
    	{
    		lie++;
    		y=n,x++;
		}
		else if(y==0&&lie%2!=0)
		{
			lie++;
			y=1,x++;
		}
		if(a[i]==res)
		{
			cout<<x<<" "<<y;
			return 0;
		}
	}
	return 0;
}
// 100pts at 9:20