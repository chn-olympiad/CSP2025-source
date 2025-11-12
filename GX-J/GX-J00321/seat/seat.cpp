#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b[10000],sum=1,ans=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
		if(i>1)
		{
			if(b[i]>b[1])
			{
				if(sum>0)
				{
					sum++;
				    if(sum>n)
					{
						sum--;
						ans++;
					}
					if(ans%2==0)
					{
						sum--;
					}	
					if(sum<0)
					{
						sum++;
						ans++;
					}
				}
			}
		}
	}
	cout<<sum<<"  "<<ans;
	return 0;
}
