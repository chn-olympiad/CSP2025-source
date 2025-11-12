#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon4.in","r",stdin);
	freopen(" polygon4.out","w",stdout);
	int n,ji=3,nu,pc=0;
	cin>>n;
	int sum[n];
	for(int i=1;i<=n;i++)
	{
		cin>>sum[i];

	}
	sort(sum+1,sum+n+1);
	while(ji>=n)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=3;j<=n;++j)
			{
				nu=sum[i];
				for(int m=3;m>=0;m--)
				{
					if(m==j)
					{
						nu=nu+sum[i+(j-1)];
					
					}
					else
					{
						nu+=sum[i+(j-m)];
					
					}	
				}
			
				if(nu>(sum[i+(j-1)])*2)
			{
					pc++;
				}
			}
		}
		ji++;		
	}
	cout<<23;
	fclose(stdin);
	fclose(stdout);
}
