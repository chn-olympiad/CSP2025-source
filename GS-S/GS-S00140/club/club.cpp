#include<bits/stdc++.h>

using namespace std;

int T;
int n;
int a[100005],b[100005],c[100005];
int aa,ab,ac;
int ans;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--)
	{
		cin >> n;
		aa=ab=ac=0;
		ans=0;
		for(int i=0;i<n;i++)
		{
			cin >> a[i] >> b[i] >> c[i];
		}
		for(int j=0;j<n;j++)
		{
			int m=-1;
			int mn;
			for(int i=0;i<n;i++)
			{
				if(aa<n/2&&ab<n/2&&ac<n/2)
				{
					m=max(max(m,a[i]),max(b[i],c[i]));
					if(a[i]>m||b[i]>m||c[i]>m)
					{
						mn=i;
					}
				}
				else if(aa<n/2&&ab<n/2)
				{
					m=max(max(m,a[i]),b[i]);
					if(a[i]>m||b[i]>m||c[i]>m)
					{
						mn=i;
					}
				}
				else if(aa<n/2&&ac<n/2)
				{
					m=max(max(m,a[i]),c[i]);
					if(a[i]>m||b[i]>m||c[i]>m)
					{
						mn=i;
					}
				}
				else if(ab<n/2&&ac<n/2)
				{
					m=max(m,max(b[i],c[i]));
					if(a[i]>m||b[i]>m||c[i]>m)
					{
						mn=i;
					}
				}
				else if(aa<n/2)
				{
					m=max(m,a[i]);
					if(a[i]>m||b[i]>m||c[i]>m)
					{
						mn=i;
					}
				}
				else if(ab<n/2)
				{
					m=max(m,b[i]);
					if(a[i]>m||b[i]>m||c[i]>m)
					{
						mn=i;
					}
				}
				else if(ac<n/2)
				{
					m=max(m,c[i]);
					if(a[i]>m||b[i]>m||c[i]>m)
					{
						mn=i;
					}
				}
			}
			ans+=m;
			//cout << mn << "mn" << endl << m << "m" << endl;
			if(a[mn]>b[mn]&&a[mn]>c[mn])
			{
				aa++;
			}
			else if(b[mn]>c[mn]&&b[mn]>a[mn])
			{
				ab++;
			}
			else if(c[mn]>a[mn]&&c[mn]>b[mn])
			{
				ac++;
			}
			a[mn]=b[mn]=c[mn]=-999;
			m=-1;
		}
		cout << ans << endl;
	}
}
