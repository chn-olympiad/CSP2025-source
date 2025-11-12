#include<bits/stdc++.h>
using namespace std;
int a[100005];
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
    int sum=0,max=0;
    if(n<3)
    {
    	cout<<"0";
	}
    if(n==3)
    {
    	for(int i=0;i<n;i++)
    	{
    		if(a[i]>max)
    		{
    			max=a[i];
			}
    		sum+=a[i];
		}
		if(sum>2*max)
		{
			cout<<"1";
		}
	}
	return 0; 
}

