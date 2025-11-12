#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,y,s=0,p,q,i;
	cin>>x>>y;
	int a[x*y];
	for(i=0;i<x*y;i++)
	{
		cin>>a[i];
		if(a[i]>=a[0])
			s++;
	}
	p=s/x+!(s%x==0);
	if(p%2==0)
		q=x+1-s%x-x*(s%x==0);
	else
		q=s%x+x*(s%x==0);
	cout<<p<<" "<<q;
}
