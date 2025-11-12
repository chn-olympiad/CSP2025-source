#include<bits/stdc++.h>
using namespace std;
int read()
{
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
bool cmp(int x,int y)
{
	return x>y;
}
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n=read(),m=read();
	for(int i=1;i<=n*m;i++)
		a[i]=read();
	int p=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==p){p=i-1;break;}
	int x=p/(n*2),y=p%(n*2);
	if(y<n) write(x*2+1),putchar(' '),write(y+1);
	else write(x*2+2),putchar(' '),write(m-(y-n));
	return 0;
}
