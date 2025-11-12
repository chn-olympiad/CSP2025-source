#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=1e5+5;
struct node
{
	int a[3],rk[2],p;
}c[N];
int t,n,b[3],ans;
bool cmp(node x,node y)
{
	return x.p>y.p;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++)
		{
			int mx=-1,mx2=-1;
			for(int j=0;j<3;j++)
			{
				cin>>c[i].a[j];
				if(mx<c[i].a[j])
				{
					mx2=mx;
					mx=c[i].a[j];
					c[i].rk[1]=c[i].rk[0];
					c[i].rk[0]=j;
				}
				else if(mx2<c[i].a[j])
				{
					mx2=c[i].a[j];
					c[i].rk[1]=j;
				}
			}
			c[i].p=mx-mx2;
		}
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			int x=c[i].rk[0],y=c[i].rk[1];
			if(b[x]<n/2)
			{
				b[x]++;
				ans+=c[i].a[x];
			}
			else
			{
				b[y]++;
				ans+=c[i].a[y];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
