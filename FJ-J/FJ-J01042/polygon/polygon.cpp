#include<bits/stdc++.h>
using namespace std;
int n,a[7500],b;
long long js;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cout<<"0";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	cin>>a[i];
	b+=a[i];
    }
    for(int i=1;i<=n;i++)
    {
    	for(int j=i;j<=n;j++)
    	{
    		if(a[j]>=a[i])
    		    swap(a[j],a[i]);
		}
	}
    if(n==3)
    {
    	if(a[1]*2<b)
    	{
    		cout<<"1";
		}
		else cout<<"0";
		
		return 0;
	}
	else
	{
		return 0;
	}
	return 0;
}
