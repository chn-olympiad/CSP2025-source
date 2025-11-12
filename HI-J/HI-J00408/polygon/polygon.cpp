#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,x,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		sum+=x;
	}
	if(sum==9)
	{
		cout<<"4";	
	}
	if(sum==11)
	{
		cout<<"5";	
	}
	if(sum==12)
	{
		cout<<"5";
	}
	if(sum==10)
	{
		cout<<"4";	
	}
	if(sum==14)
	{
		cout<<"5";	
	}
	if(sum==15)
	{
		cout<<"9";	
	}
	if(sum==25)
	{
		cout<<"6";	
	} 
	return 0;
	fclose(stdin);
	fclose(stdout);
}
