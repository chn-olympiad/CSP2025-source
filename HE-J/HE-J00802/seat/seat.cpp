#include<bits/stdc++.h>
using namespace std;
int n,m,x=1,v,a[13][13],b[103],t;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    t=n*m;
    for(int i=1;i<=t;i++)
    {
    	cin>>b[i];
    	if(i==1)v=b[i];
    	if(b[i]>v)x++;
	}
	int s=ceil(x*1.0/n);
	int sx;
	if(s%2==0)
	{
		if(x%n==0)sx=1;
		else sx=n-(x%n)+1;
	}
	if(s%2!=0)
	{
		if(x%n==0)sx=n;
		else sx=x%n;
	}
	cout<<s<<" "<<sx;
	return 0;
}
