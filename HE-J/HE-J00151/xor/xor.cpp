#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 150;

int n,ans;
long long k;
int a[N];
int xo[N][N];//x到y的异或和 
int g[N];

void check(int sum,int cur)
{
	if(cur == n+1)
	{
		ans = max(ans,sum);
		return ;
	}
	
	if(g[cur] != 0)
		return check(sum+1,g[cur]+1);
	return check(sum,cur+1); 
}

int main()
{
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		xo[i][i] = a[i];
		if(a[i] == k)
			g[i] = i;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			xo[j][j+i] = xo[j][j+i-1]^a[j+i];
			if(xo[j][j+i] == k)
			{
				if(g[j] == 0)
					g[j] = j+i;
			}
		}
	}
	
	check(0,1);
	
	cout<<ans;
	return 0;
}
