#include<bits/stdc++.h>
using namespace std;
int a[105],maps[105][105];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r=n*m;
	for(int i=1;i<=r;i++)
	{
		cin>>a[i];
	}
	int w=a[1],p;
	sort(a+1,a+r+1,cmp);
	for(int i=1;i<=r;i++)
	{
		if(a[i]==w) p=i;
	}
	double j=p*1.0/n*1.0;
	int x=ceil(j),y;
	if(x%2==0){
		if(p%n==0) y=1;
		else{
			y=m-p%n+1;
		}
	}else{
		if(p%n==0) y=m;
		else y=p%n;
	}
	cout<<x<<' '<<y;
	return 0;
}