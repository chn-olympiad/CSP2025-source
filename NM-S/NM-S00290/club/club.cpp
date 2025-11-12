#include <bits/stdc++.h>
using namespace std;
long long f[3];
int main()
{
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	long  long n,t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		
	    cin>>n;
		for(int j=0;j<n;j++)
		{
			cin>>f[j];
            long long  k=0,sum=0;
			
			if(f[j]>f[j+1]&& k<n)
			{
				sum+=f[j];
				k++;
				cout<<sum;
				
			}
			if(	f[j]>f[j+1]&&k==n)
			{
				f[j]=f[j+1];
				sum+=f[j];
				cout<<sum;
			}
		}
		
	}		
	cout<<endl;		
		
     return 0;
}
