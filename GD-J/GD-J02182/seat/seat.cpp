#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10010],c,r,R,f,zu,w;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int num=n*m;
	for(int i=0;i<num;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>=a[0])f++;
	}
	zu=f/(2*n);
	w=f%(2*n);
	if(w==0)
	{
		r=1;
		c=zu*2;
	}
	else if(w>n)
	{
		r=n-(w-n)+1;
		c=zu*2+2;
	}
	else
	{
		r=w;
		c=zu*2+1;
	}
	printf("%d %d",c,r);
	return 0;
}
