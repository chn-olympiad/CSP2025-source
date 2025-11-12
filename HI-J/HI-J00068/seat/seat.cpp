#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main()
{
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m;
    string s;
    cin>>n>>m;
    int x=1,y=1;
    for(int i=1;i<=n*m;i++)
    {
    	cin >>a[i];
	}
    for (int i= 1;i<= n*m;i++)
	{
    	if(a[1]<a[i])
		{
    		if(x<=n)
		    {
    			
    			x++;
					
			}
			else
			{
				y++;
			}
		}
		else
		{
			if(x>=1)
			{
				x--;
			}
			else
			{
				x++;
			}
		}
	}
	if(x>n)
	{
		y++;
		x-=n;
	}
	cout<<x<<" "<<y;
    
	fcloes(stdin);
    fcloes(stdout);
	return 0;
}
