#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout") ;
	int a,b,d,e,f;
	cin>>a>>b;
	int c[100];
	for(int i=0;i<a*b;i++)
	{
		cin>>c[i];
		
	} 
	for(int i=1;i<a*b;i++)
	{
		if(c[i]>c[0])
		{
			d++;
		}
		
	} 
	d+=1;
	e=d/a;
	f=d%a;
	if(e%2==0)
	{
		cout<<e+1<<" "<<b-f;
	}
	else
	{
		cout<<e<<" "<<f+1;
	}
	  
	return 0;
}

