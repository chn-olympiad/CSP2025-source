#include<bits/stdc++.h>
using namespace std;
int n,t,sum=0;
int a_sum=0,b_sum=0,c_sum=0;
int a[1000005],b[1000005],c[1000005],d[100005];
int main()
{
	freopen("club.in","w",stdin);
	freopen("club.out","r",stdout);
	cin>>t>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(a_sum<=n/2&&b_sum<=n/2&&c_sum<=n/2)
			{
				if(max(a[i],max(b[i],c[i]))==a[i]) 
				{
					a_sum++;
					sum+=a[i];
				}
					if(max(a[i],max(b[i],c[i]))==b[i]) 
				{
					b_sum++;
					sum+=b[i];
				}
					if(max(a[i],max(b[i],c[i]))==c[i]) 
				{
					c_sum++;
					sum+=c[i];
				}
			}
		}
		for(int i=1;i<=t;i++)
		cout<<sum<<"\n";
	return 0;
}

