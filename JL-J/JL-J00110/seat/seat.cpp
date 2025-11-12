#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,z,h,b;
	cin>>z>>h;
	int mc=1;
	cin>>a;
	for(int i=0;i<z*h-1;i++)
	{
		cin>>b;
		if(b>a)
		{
			mc++;
		}
	}
	if(mc%h==0)
	{
		cout<<mc/h<<" "<<h;
	}
	else
	{
		cout<<mc/h+1<<" ";
		if((mc/h+1)%2==1)
		{
			cout<<mc%h;
		}
		else
		{
			cout<<h-(mc%h)+1;
		}
	}
	return 0;
}
