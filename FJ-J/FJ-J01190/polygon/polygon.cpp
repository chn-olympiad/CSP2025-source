#include<bits/stdc++.h>
using namespace std;
const int N=5e3+7;
const int M=998244353;

int n;
int a[N];
bool flag=0;
int ans=0;

int C(int x, int y)
{
	int res=1;
	for(int i=0;i<x;i++)
	{
		res=res*(y-i)%M;
	}
	for(int i=1;i<=x;i++)
	{
		res=res/i%M;
	}
	return res;
}

void dfs(int m, int k, int all, int mx)
{
	if(k>=3&&all>(mx*2)){
		ans++;
		//printf("%d %d %d %d\n", m, k, all, mx);
	}
	for(int i=m+1;i<=n;i++)
	{
		dfs(i, k+1, all+a[i], max(mx, a[i]));
	}
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", a+i);
	for(int i=1;i<=n;i++)
		if(a[i]!=1){
			flag=1;break;
		}
	if(!flag)
	{
		int res=0;
		for(int i=3;i<=n;i++)
		{
			res=(res+C(i, n))%M;
		}
		printf("%d", res);
		return 0;
	}
	if(n==3)
	{
		sort(a+1, a+n+1);
		if(a[1]+a[2]+a[3]>a[3]*2) printf("1");
		else printf("0");
		return 0;
	}
	dfs(0, 0, 0, 0);
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
