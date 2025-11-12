#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a1[N],a2[N],a3[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n;
	while(t--)
	{
		cin>>n;
		int sum1=0,sum2=0,sum3=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a1[i]>>a2[i]>>a3[i];
			int m=max(a1[i],max(a2[i],a3[i]));
			if(a1[i]==m)
			{
				if(sum1<n/2)
				{
					sum1++;
					ans+=m;
				}
			}
			else if(a2[i]==m)
			{
				if(sum2<n/2)
				{
					sum2++;
					ans+=m;
				}
			}
			else if(a3[i]==m)
			{
				if(sum3<n/2)
				{
					sum3++;
					ans+=m;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
 } 
