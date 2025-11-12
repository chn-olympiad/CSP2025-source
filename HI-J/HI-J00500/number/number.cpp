#include<iostream>
using namespace std;
int main{
	    freopen("number.in","r",stdin);
	    freopen("number.out","w",stdout);
	string a[10000];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(n==1)
		{
			cout<<a[i];
			return 0;
		}
	    int sum=0;
	    if(a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9')
	    {
	    	sum=a[i];
	    	for(int j=1;j<=a;j++)
	    	{
	    		if(a[j]>sum)
	    		{
	    				sum=a[j];
				}
			}
		}
		       cout<<sum;
	}
    return 0;
}
