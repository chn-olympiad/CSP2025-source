#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b,s,x=1,y=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[0];
	b=a[0];
	for(int i=1;i<n*m;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n*m);
	for(int i=n*m;i>=0;i--)
	{
		if(a[i]!=b)s++;
		else break;
	}
	while(--s)
	{
		if(y%2)
		{
			x++;
			if(x>n)y++,x--;
		}
		else
		{
			x--;
			if(x<=0)y++,x++;
		}
	}
	cout<<y<<" "<<x;
	
	return 0;
}
