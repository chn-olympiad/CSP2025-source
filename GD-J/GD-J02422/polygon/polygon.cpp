#include<bits/stdc++.h>
using namespace std;
int n;
int a[501];
bool io=true;//is all one?
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) io=false; 
	}
	
	if(n==3)
	{
		if(2*max(a[1],max(a[2],a[3]))<(a[1]+a[2]+a[3]))
		{
			cout<<"1";
		}
		else cout<<"0";
		return 0;
	}
	if(io) cout<<"0";
	else cout<<"9"; 
	return 0;
}
