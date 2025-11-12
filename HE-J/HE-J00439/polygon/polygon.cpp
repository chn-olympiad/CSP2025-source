#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
 	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	if(a[0]+a[1]>=a[2])
	{
		cout<<1<<endl;
	}
	else
	{
		cout<<0<<endl;
	}
}
