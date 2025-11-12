#include<bits/stdc++.h>
using namespace std;
int sum,n,a[5005],maxx;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
		
	maxx=max(a[1],a[2]);
	maxx=max(a[2],a[3]);
	if(sum>2*maxx)
	  cout<<1;
	else
	  cout<<0;
}