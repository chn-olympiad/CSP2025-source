#include<bits/stdc++.h>
using namespace std;
int b[1000000];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a;
	cin>>a;
	int maxx=-1;
	int ans=0;
	for(int i=1;i<=a;i++)
	{
		cin>>b[i];
		maxx=max(maxx,b[i]);
	}
	if(b[1]+b[2]+b[3]>2*maxx)
	{
		cout<<1<<endl;
	}	
	return 0;
} 


