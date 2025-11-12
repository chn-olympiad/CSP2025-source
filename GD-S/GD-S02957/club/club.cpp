#include<iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int a[100010][5];
int vis[100010];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		long long sum=0;
		for(int i=1; i<=n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=1; i<=n; i++)
		{
			int maxn=max(a[i][1],max(a[i][2],a[i][3]));
			if(a[i][1]==maxn)
			{
				cnt1++;
				vis[i]=1;
			}
			else if(a[i][2]==maxn)
			{
				cnt2++;
				vis[i]=2;
			}
			else
			{
				cnt3++;
				vis[i]=3;
			}
			sum+=a[i][vis[i]];
		}
		if(cnt1>n/2)
		{
			int b[cnt1+10];
			memset(b,0,sizeof(b));
			int cur=0;
			for(int i=1; i<=n; i++)
			{
				if(vis[i]==1)
				{
					b[++cur]=a[i][1]-max(a[i][3],a[i][2]);
				}
			}
			sort(b+1,b+cnt1+1);
			for(int i=1; i<=cnt1; i++)
			{
				if(cnt1==n/2)
				{
					break;
				}
				sum-=b[i];
				cnt1--;
			}
		}
		else if(cnt2>n/2)
		{
			int b[cnt2+10];
			memset(b,0,sizeof(b));
			int cur=0;
			for(int i=1; i<=n; i++)
			{
				if(vis[i]==2)
				{
					b[++cur]=a[i][2]-max(a[i][3],a[i][1]);
				}
			}
			sort(b+1,b+cnt2+1);
			for(int i=1; i<=cnt2; i++)
			{
				if(cnt2==n/2)
				{
					break;
				}
				sum-=b[i];
				cnt2--;
			}
		}
		else if(cnt3>n/2)
		{
			int b[cnt3+10];
			memset(b,0,sizeof(b));
			int cur=0;
			for(int i=1; i<=n; i++)
			{
				if(vis[i]==3)
				{
					b[++cur]=a[i][3]-max(a[i][2],a[i][1]);
				}
			}
			sort(b+1,b+cnt3+1);
			for(int i=1; i<=cnt3; i++)
			{
				if(cnt3==n/2)
				{
					break;
				}
				sum-=b[i];
				cnt3--;
			}
		}
		cout << sum << endl;
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
	}
	return 0;
} 
