#include <iostream>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[100005][5],a1[20005]={0};
		long long ans=0;
		for(int i=1; i<=n; i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			a1[a[i][1]]++;
		}
		int i=n/2,j=1;
		while(i)
		{
			if(a1[j]>0)
			{
				if(a1[j]>i)
				{
					ans=ans+i*j;
					break;
				}
				else
				{
					ans=ans+a1[j]*j;
					i-=j;
				}
			}
			j++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
