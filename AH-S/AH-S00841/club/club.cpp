#include <bits/stdc++.h>
using namespace std;
int t,a[110000],n,x;
bool bj(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int s=0;
		cin>>n;
		if(n>2)
		{
			for(int i=1;i<=n;i++)
			{
				cin>>x>>a[i]>>x;
			}
			sort(a+1,a+n+1,bj);
			for(int i=1;i<=n/2;i++)
			{
				s+=a[i];
			}
			cout<<s<<endl;
		}
		else
		{
			int a[4],b[4];
			cin>>a[1]>>a[2]>>a[3]>>b[1]>>b[2]>>b[3];
			for(int i=1;i<=3;i++)
			{
				for(int j=1;j<=3;j++)
				{
					if(i==j)
					{
						continue;
					}
					s=max(s,a[i]+b[j]);
				}
			}
			cout<<s<<endl;
		}
	}
	return 0;
}
