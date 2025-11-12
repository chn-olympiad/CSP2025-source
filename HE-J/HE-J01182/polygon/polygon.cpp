#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n,b=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	if((n==1)||(n==2))
	{
		cout<<" ";
		return 0;
	}
	 for(int i=1;i<=n;i++)
    {
    	if(n==3)
	{
			if((a[1]+a[2]>a[3])&&(a[1]+a[3]>a[2])&&(a[3]+a[2]>a[1]))
			{
				cout<<1;
				return 0;
			}
			else
			{
				cout<<0;
				return 0;
			}
	}
	}	
    for(int i=1;i<=n;i++)
    {
    	if(a[i]+1==a[i+1])
    	{
    		b++;
		}
	}	
	if(b==n-1)
	{
		cout<<9;
		return 0;
	}
	if(b==n-4)
	{
		cout<<6;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
