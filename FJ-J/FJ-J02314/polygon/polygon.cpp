#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin); 
	freopen("polygon.out","w",stdout); 
	int n,ans=0;
	long long int mod=998244353;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
		for(int i=0;i<n-2;i++)
		{
			int j=a[i];
			for(int ii=1+i;ii<n-1;ii++)
			{
				int k=a[ii];
				for(int iii=ii+1;iii<n;iii++)
				{
					int l=a[iii];
					if(j+k>l)
					{
						cout<<j<<" "<<k<<" "<<l<<endl;
						ans++;
					}
				}
			}
			
		}
	cout<<ans;
	return 0;
}
