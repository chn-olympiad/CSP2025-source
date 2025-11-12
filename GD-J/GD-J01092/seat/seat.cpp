#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],num,k,s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++)
    {
    	cin>>a[i];
	}
	num=a[1];
    sort(a+1,a+1+(n*m));
    for(long long i=n*m;i>=1;i--)
    {
    	k++;
    	if(a[i]==num)
    	{
    		s=k/n;
    		if(s==0||k==n)
    		{
    			cout<<1<<" "<<k;
    			return 0;
			}
    		else if(s%2==0)
    		{
    			if(k==s*n)
    			{
    				cout<<s<<" "<<1;
    				return 0;
				}
				else 
				{
					cout<<s+1<<" "<<k-s*n;
					return 0;
				}
			}
			else
			{
				if(k==s*n)
				{
					cout<<s<<" "<<n;
				}
				else
				{
					cout<<s+1<<" "<<n+1-(k-s*n);
					return 0;
				}
			}
		}
	}
	return 0;
} 
