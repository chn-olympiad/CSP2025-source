#include<bits/stdc++.h>
using namespace std;
int a[100005][5],m[100005],s[5],k[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,ans=0,x;
	cin>>t;
	while (t--)
	{
		ans=0;
		s[1]=s[2]=s[3]=0;
		cin>>n;
		for (int i=1;i<=n;++i)
		{
			for (int j=1;j<=3;++j)
			{
				cin>>a[i][j];
			}
			x=max(max(a[i][1],a[i][2]),a[i][3]);
			ans+=x;
			if (a[i][1]==x)
			{
				++s[1];
				m[i]=1;
			}
			else if (a[i][2]==x)
			{
				++s[2];
				m[i]=2;
			}
			else
			{
				++s[3];
				m[i]=3;
			}
		}
		for (int i=1;i<=3;++i)
		{
			if (s[i]>n/2)
			{
				x=0;
				for (int j=1;j<=n;++j)
				{
					if (m[j]==i)
					{
						if (i==1)
						{
							k[++x]=a[j][1]-max(a[j][2],a[j][3]);
						}
						else if (i==2)
						{
							k[++x]=a[j][2]-max(a[j][1],a[j][3]);
						}
						else
						{
							k[++x]=a[j][3]-max(a[j][1],a[j][2]);
						}
					}
				}
				sort(k+1,k+x+1);
				for (int j=1;j<=s[i]-n/2;++j)
				{
					ans-=k[j];
				}
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
