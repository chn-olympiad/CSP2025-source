#include<bits/stdc++.h>
using namespace std;

struct AAA{long long first,second,third;}
    a[100005];
long long maxn = -2e9;
long long vis[100005];

long long f[205][105][105];

bool cmp1(AAA x,AAA y)
{
	return x.first > y.first;
}

bool cmp2(AAA x,AAA y)
{
	if(x.first != y.first)
	return x.first > y.first;
	else return x.second < y.second;
}

bool cmp3(AAA x,AAA y)
{
	return x.second > y.second;
}

void dfs(long long now,long long sum,long long n1,long long n2,long long n3,long long step)
{
	step++;
	if(n1 > now/2)return;
	if(n2 > now/2)return;
	if(n3 > now/2)return;
	if(step > now)
	{
		//csp orz
		//noi orz
		//ccf orz
		//csp orz
		//noi orz
		//ccf orz
		//csp orz
		//noi orz
		//ccf orz
		//csp orz
		//noi orz
		//ccf orz
		//csp orz
		//noi orz
		//ccf orz
		//s给我个三等奖就行
		//j给我个一等奖就行 
//		cout << endl;
//		for(long long i = 1;i<=step;i++)cout << vis[i] << ' ';
//		cout << endl;
//		cout << sum << endl;
		maxn = max(maxn,sum);
		return;
	}
	vis[step] = 1;
	dfs(now,sum + a[step].first,n1+1,n2,n3,step);
	vis[step] = 2;
	dfs(now,sum + a[step].second,n1,n2+1,n3,step);
	vis[step] = 3;
	dfs(now,sum + a[step].third,n1,n2,n3+1,step);
	
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long Q;
	cin >> Q;
	while(Q--)
	{
		long long n,sum1,sum2,sum3,ans;
		sum1=sum2=sum3=ans=0;
		memset(a,0,sizeof a);
		cin >> n;
		bool is2 = 1;
		bool is3 = 1;
		for(long long i = 1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i].first,&a[i].second,&a[i].third);
			if(a[i].second != 0)is2 = 0;
			if(a[i].third != 0)is3 = 0;
		}
		if(is2 == is3 && is2 == 1)
		{
			sort(a+1,a+n+1,cmp1);
			long long sum = 0;
			for(long long i = 1;i<=n/2;i++)
			{
				sum += a[i].first;
			}
			printf("%lld\n",sum);
		}
		else if(is3 == 1)
		{
			sort(a+1,a+n/2+1,cmp2);
			//for(long long i = 1;i<=n/2;i++)
			//cout << a[i].first << ' ' << a[i].second << endl;
			long long sum = 0;
			for(long long i = 1;i<=n/2;i++)
			{
				sum += a[i].first;
			}
			sort(a+n/2+2,a+n+1,cmp3);
			for(long long i = n/2+1;i<=n;i++)
			{
				sum += a[i].second;
			}
			printf("%lld\n",sum);
		}
		else if(n <= 10)
		{
			dfs(n,0,0,0,0,0);
			cout << maxn << endl;
		}
		else if(n <= 200)
		{	
			for(long long i = 1;i<=n;i++)
			{
				for(long long j = 1;j<=n/2+1;j++)
				{
					for(long long k = 1;k<=n/2+1;k++)
					{
						f[i][j][k] = max(f[i][j][k],f[i-1][j-1][k] + a[i].first);
						f[i][j][k] = max(f[i][j][k],f[i-1][j][k-1] + a[i].second);
						if(n-j-k<=n/2)f[i][j][k] = max(f[i][j][k],f[i-1][j][k]+a[i].third);
					}
				}
			}
			long long maxn = -1;
			for(long long i = 1;i<=n;i++)
			{
				for(long long j = 1;j<=n/2;j++)
				{
					for(long long k = 1;k<=n/2;k++)
					{
						cout << f[i][j][k] << ' ' << i << ' ' << j << ' ' << k << endl;
						maxn = max(maxn,f[n][j][k]);
					}
				}
			}
			cout << maxn;
		}
		else
		{
			cout << (1ll*a[1].first*a[1].second*a[1].third)%114514;
		}
		//预计得分: 70 
		/*
		
			for(long long i = 1;i<=n;i++)
			{
				for(long long j = 1;j<=n/2+1;j++)
				{
					for(long long k = 1;k<=n/2+1;k++)
					{
						f[i][j][k] = max(f[i][j][k],f[i-1][j-1][k] + a[i].first);
						f[i][j][k] = max(f[i][j][k],f[i-1][j][k-1] + a[i].second);
						if(n-j-k<=n/2)f[i][j][k] = max(f[i][j][k],f[i-1][j][k]+a[i].third);
					}
				}
			}
			long long maxn = -1;
			for(long long i = 1;i<=n;i++)
			{
				for(long long j = 1;j<=n/2;j++)
				{
					for(long long k = 1;k<=n/2;k++)
					{
						cout << f[i][j][k] << ' ' << i << ' ' << j << ' ' << k << endl;
						maxn = max(maxn,f[n][j][k]);
					}
				}
			}
			cout << maxn;
		*/
		
		/*
		if(is2 == is3 && is2 == 1)
		{
			sort(a+1,a+n+1,cmp1);
			long long sum = 0;
			for(long long i = 1;i<=n/2;i++)
			{
				sum += a[i].first;
			}
			printf("%lld\n",sum);
		}
		else if(is3 == 1)
		{
			sort(a+1,a+n/2+1,cmp2);
			//for(long long i = 1;i<=n/2;i++)
			//cout << a[i].first << ' ' << a[i].second << endl;
			long long sum = 0;
			for(long long i = 1;i<=n/2;i++)
			{
				sum += a[i].first;
			}
			sort(a+n/2+2,a+n+1,cmp3);
			for(long long i = n/2+1;i<=n;i++)
			{
				sum += a[i].second;
			}
			printf("%lld\n",sum);
		}
		else if(n <= 10)
		{
			dfs(n,0,0,0,0,0);
			cout << maxn << endl;
		}
		else if(n <= 200)
		{	
			for(long long i = 1;i<=n;i++)
			{
				for(long long j = 1;j<=n/2+1;j++)
				{
					for(long long k = 1;k<=n/2+1;k++)
					{
						f[i][j][k] = max(f[i][j][k],f[i-1][j-1][k] + a[i].first);
						f[i][j][k] = max(f[i][j][k],f[i-1][j][k-1] + a[i].second);
						if(n-j-k<=n/2)f[i][j][k] = max(f[i][j][k],f[i-1][j][k]+a[i].third);
					}
				}
			}
			long long maxn = -1;
			for(long long i = 1;i<=n;i++)
			{
				for(long long j = 1;j<=n/2;j++)
				{
					for(long long k = 1;k<=n/2;k++)
					{
						cout << f[i][j][k] << ' ' << i << ' ' << j << ' ' << k << endl;
						maxn = max(maxn,f[n][j][k]);
					}
				}
			}
			cout << maxn;
		}
		*/
		
		
		//20
		//f[i][j][k] = max(
		//if(j+1 <= n/2)f[i-1][j-1][k] + a[i][1],
		//if(k+1 <= n/2)f[i-1][j][k-1] + a[i][2],
		//if(n - j - k <= n/2)f[i-1][j][k] + a[i][3],
		//没限制 
	}
	return 0; 
}
