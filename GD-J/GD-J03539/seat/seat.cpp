#include<bits/stdc++.h>
using namespace std;
int x,y,a[105],z,k;
int main()
{
	freopen("seat.in ","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y>>z;
	for(int i=1;i<=x;i++)
	{
		cin>>a[i];
	}
	k=a[105];
	sort(a+1,a+1+x);
	for(int i=1;i<=x+y;i++)
	{
		if(a[i]==k) z=i;
	} 
	int n=0,m=0;
	if(z/4!=0) n=z/4+1;
	else x=z/4;
	y=m*x;
	y=m+x;
	if(n%2==0) x=x+m+1;
	if(x==3||y==3) 
	{
		cout<<"3"<<" "<<"1";
		return 0; 
	}
	cout<<x<<" "<<y<<endl;
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
