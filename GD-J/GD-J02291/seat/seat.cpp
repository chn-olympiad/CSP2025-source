#include<iostream>

using namespace std;

int a,n,m,r,p=1;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	r=a;
	for(int i=2;i<=n*m;i++)
	{
		cin>>a;
		if(a>r)p++; 
	}	
	int x=2*n,y=p/x,yu=p%x,l=y*2,h;
	if(yu==0) 
	{
		if(y==0) y=1;
		cout<<y*2<<" "<<1;
		return 0;
	}
    if(yu<=n&&yu!=0) 
	{
		h=yu;
		l++;
	}
    else 
    {
    	int o=p%n;
    	h=n+1-o;
    	l+=2;
	}
    cout<<l<<" "<<h;
	return 0;
}
