#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[114],x,f,cnt;
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	x=a[1];
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x)
		{
			f=i;
			break;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				cnt++;
				if(cnt==f)
				{
					cout<<i<<" "<<j<<"\n";
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				cnt++;
				if(cnt==f)
				{
					cout<<i<<" "<<j<<"\n";
					return 0;
				}
			}
		}
	}
	return 0;
}
