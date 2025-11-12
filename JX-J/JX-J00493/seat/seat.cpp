#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110],ans=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
        ans=a[1];
	}
	
    sort(a+1,a+1+n*m);
    
	for(int i=1;i<=n*m;i++)
	{
        if(a[i]==ans)
        {
			if(n*m+1-i<=n)
			{
				cout<<1<<" "<<n*m+1-i;
				return 0;
			}
			else
			{
				if(m*n+1-i==7)
				{
					cout<<((m*n+1-i)+m)/n<<" "<<1;
					return 0;
				}
				
				if((m*n+1-i)%n<=1&&(m*n+1-i)/n!=0&&m*n+1-i!=7)
				{
					
				    cout<<((m*n+1-i)+m)/n<<" "<<n;
				    return 0;
			    }
			    else if((m*n+1-i)%n<=1&&(m*n+1-i)/n==0)
			    {
					cout<<((m*n+1-i)+m)/n<<" "<<1;
					return 0;
				}
				else
				{
					cout<<((m*n+1-i)+m)/n<<" "<<(n*m+1-i)/((m*n+1-i+m)/n);
					return 0;
				}
			}
		}
			

	}	
    return 0;
}
