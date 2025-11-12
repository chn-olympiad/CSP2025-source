#include<bits/stdc++.h>
using namespace std;

int n,m,a[44444],R,flag;
int Rx,Ry;

bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	R=a[1];
	
	sort(a+1,a+1+n*m,cmp);
	
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==R) {
			flag=i;
			break;
		}
	}
	
	if(flag%n==0) {
		Rx=flag/n;
		
		if(Rx%2==1) Ry=n;
		else Ry=1;
		
	}
	else {
		Rx=flag/n+1;
		
		if(Rx%2==1) Ry=flag%n;
		else Ry=n-flag%n+1;
	}
	
	printf("%d %d",Rx,Ry);
	
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/