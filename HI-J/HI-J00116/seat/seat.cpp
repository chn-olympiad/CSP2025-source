#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
		x=a[1];
    }
    sort(a+1,a+m*n+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
    	if(a[i]==x)
    	{
    		if(i%n==0)
    		{
    			if((i/n)%2==0)
    			{
    				cout<<i/n<<" "<<"1";
				}
				else if((i/n)%2!=0)
    			{
    				cout<<i/n<<" "<<n;
				}
			}
			else if(i%n!=0)
    		{
    			if((i/n+1)%2==0)
				{
					cout<<i/n+1<<" "<<n-i%n+1;
				} 
    			else if((i/n+1)%2!=0)
				{
					cout<<i/n+1<<" "<<i%n;
				} 	
				}
			}
		}
	return 0; 
}

