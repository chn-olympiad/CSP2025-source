#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.in","w",stdout);
	int b,c[5000];
	cin>>b;
	for(int i=0;i<b;i++)
	{
		cin>>c[i];
	}
	sort(c,c+3);
	if(c[2]>=(c[0]+c[1]))
	{
		cout<<9;
	}
	else
	{
		cout<<6;
	}
}
