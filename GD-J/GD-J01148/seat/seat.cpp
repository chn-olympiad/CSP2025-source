#include <iostream>
using namespace std;
const int MAXN=10+20;
int n,m;
int littleR,pos=1;
void getXY()
{
	int x=0,y=0;
	if(pos%n==0)
	{
		x=pos/n;
		y=n;
		if(x%2==0)y=1;
	}
	else
	{
		y=pos%n;
		x=((pos-y)/n)+1;
		if(x%2==0)y=n-y+1;
	}
	printf("%d %d",x,y); 
	return;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&littleR);
	int input=0;
	for(int i=1;i<n*m;i++)
	{
		scanf("%d",&input);
		if(input>littleR)pos++;
	}
	getXY();
	return 0;
	
}
