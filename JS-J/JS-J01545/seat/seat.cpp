#include<bits/stdc++.h>
using namespace std;

const int SZ=150;

int n,m;
int a[SZ];

bool cmp(int a,int b)
{
	return a>b;
}

int find(int a[],int sz,int num)
{
	for(int i=1;i<=sz;i++)
		if(a[i]==num)
			return i;
	return -1;
}

int main()
{	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	int x=1,y=1;
	int sz=n*m;
	
	for(int i=1;i<=sz;i++)cin>>a[i];
	int num=a[1];
	
	sort(a+1,a+sz+1,cmp);
	
	int pos = find(a,sz,num);
	
	x = ceil(1.0*pos/n);
	int tmp = pos % n;
	if(x%2==0)
	{
		if(tmp==0)y=1;
		else y = n - tmp + 1 ;
	}
	else 
	{
		if(tmp==0)y=n;
		else y=tmp;
	}
	
	printf("%d %d",x,y);
	
	return 0;
}
