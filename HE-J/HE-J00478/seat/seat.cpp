#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
int main()
{
	preopen("seat.in","r",std);
	preopen("seat.out","w",std);
	int n,x,m,l=0,h=0,num=0;
	cin>>m>>n;
	cin>>x;
	for(int i=0;i<n*m-1;i++)
	{
		cin>>a[i];
		if(x>a[i])
		{
			num++;
		}
	}
	if(num==0)
	{
		l=1;
		h=1;
	}
	
	if(num%(2*m)+1>m)
	{
		l=l+1;
	}
	if(num!=0)
	{
		l=l+num/(2*m)+num/(2*m);
	}		
	
	h=h+num%(2*m)+1;
	             
	
	if(num==0)
	{
		l=1;
		h=1;
	}
	cout<<l<<" "<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
