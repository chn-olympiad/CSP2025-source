#include <bits/stdc++.h>
using namespace std;
const int N = 2e4+5;
int t, n;
int a[N],b[N],c[N];
void solve(int n,bool flag)
{
	if(flag == false)
	{
		sort(a+1,a+1+n);
		int sum = 0;
		for(int i = n;i > n/2;i--) sum += a[i];
		cout << sum << '\n';
		return;
	}
	if(n==2)
	{
		int maxn = -1;
		maxn = max(maxn,a[1]+b[2]);
		maxn = max(maxn,a[1]+c[2]);
		maxn = max(maxn,b[1]+a[2]);
		maxn = max(maxn,b[1]+c[2]);
		maxn = max(maxn,c[1]+a[2]);
		maxn = max(maxn,c[1]+b[2]);
		cout << maxn << '\n';
	}
	if(n==4)
	{
		int maxn = -1,sum = 0;
		for(int i = 1;i <= 3;i++)
		{
			for(int j=1;j<=3;j++)
			{
				for(int k=1;k<=3;k++)
				{
					for(int kk=1;kk<=3;kk++)
					{
						int count_a=0,count_b=0,count_c=0;
						if(i==1)count_a++;if(j==1)count_a++;if(k==1)count_a++;if(kk==1)count_a++;
						if(i==2)count_b++;if(j==2)count_b++;if(k==2)count_b++;if(kk==2)count_b++;
						if(i==3)count_c++;if(j==3)count_c++;if(k==3)count_c++;if(kk==3)count_c++;
						if(count_a>2||count_b>2||count_c>2) continue;
						if(i==1)sum += a[1];if(i==2)sum += b[1];if(i==3)sum+=c[1];
						if(j==1)sum += a[2];if(j==2)sum += b[2];if(j==3)sum+=c[2];
						if(k==1)sum += a[3];if(k==2)sum += b[3];if(k==3)sum+=c[3];
						if(kk==1)sum += a[4];if(kk==2)sum += b[4];if(kk==3)sum+=c[4];
						maxn = max(maxn,sum);
					}
				}
			}
		}
		cout << maxn << '\n';
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> t;
	while(t--)
	{
		cin >> n;
		bool flag = false;
		for(int i = 1;i <= n;i++) 
		{
			cin >> a[i]>>b[i]>>c[i];
			if(b[i]!=0 || c[i] != 0) flag = true;
		}
		solve(n,flag);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
	}
	return 0;
}
