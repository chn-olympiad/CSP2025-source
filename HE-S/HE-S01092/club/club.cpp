#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,k=0,a[100005],b[100005],c[100005];
	cin>>t;
	while(k!=t)
	{
		k+=1;
		cin>>n;
		if(n%2==0)
		{
		    for(int i=1;i<=n;i++)
		    {
		    	cin>>a[i]>>b[i];
			}
		}
		else
		{
			return 0;
		}
		
	}	
	return 0;
}
