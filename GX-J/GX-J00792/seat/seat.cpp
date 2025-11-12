#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,a[1001],b,k;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int v=n*m;
	for(int i=1;i<=v;i++)
		cin>>a[i];
	b=a[1];
	sort(a+1,a+v+1,cmp);
	for(int i=1;i<=v;i++)
		if(a[i]==b)
			k=i;
	int x=k/n,y=k%m;
	if(y==0)
		cout<<x<<" "<<m;
	else
	{
		x+=1;
		if(x%2==0)
			y=n-y+1;
		cout<<x<<" "<<y;
	}
	return 0;
}
