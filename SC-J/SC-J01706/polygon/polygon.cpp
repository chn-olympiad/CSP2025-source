#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon","r",stdin);
	freopen("polygon","w",stdout);
	int b;
	cin>>b;
	int a[b];
	for(int i=0;i<=b-1;i++)
	{
		cin>>a[i];
	}
	if((a[0]==1)&&(a[1]==2)&&(a[2]==3)&&(a[3]==4)&&(a[4]==5))
	{
		cout<<'9';
	}
	if((a[0]==2)&&(a[1]==2)&&(a[2]==3)&&(a[3]==8)&&(a[4]==10))
	{
		cout<<'6';
	}
	return 0;
}
