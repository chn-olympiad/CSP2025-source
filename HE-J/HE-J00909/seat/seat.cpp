#include<bits/stdc++.h>
using namespace std;


int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	int n,m,c=0,r=0,num=0; 
	cin>>n>>m;
	int a[n*m];
	for(int o=0;o<n*m;o++)
	{
		cin>>a[o];
	}
	for(int k=1;k<n*m;k++)
	{
		if(a[0]<a[k])
		{
			num++;
		}
	}
	for(int j=0;j<num;j++)
	{
		r=r+1;
		if(r=m)
		{
			c=c+1;	
		}		
	}
	if(c%2==0)
	{
		r=m-r%m;	
	}
	cout<<c<<r;
	return 0;
} 
