#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node
{
	int v,id;
}s[N];
struct kk
{
	int m,id2;
}s2[N];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		int n,ans=0;
		cin>>n;
		int u=n/2;
		int c[n];
		int v[n][4];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>v[i][j];
				if(j==1)
				{
					c[i]=v[i][j];
				}
			}
		}
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
		//	cout<<c[i]<<endl;
			if(i<=u)
			{
				ans+=c[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
