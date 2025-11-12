#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],b[N],c[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		sort(c+1,c+n+1);
		int mx=INT_MIN;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j!=i)
				{
					mx=max(mx,a[i]+b[j]);
				}
			}
		}
		cout<<mx<<endl;
	}
	return 0;
}
