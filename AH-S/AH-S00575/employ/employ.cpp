#include<cstdio>
#include<algorithm>
#define MOD 998244353
#define N 500
int n,m,a[N],b[N],ans;
//long long A[N+1][N+1],C[N+1][N+1],ans;
bool k[N],k1[N];
char s[N+1];
/*void InitAC(const int &n)
{
	for(int i=1;i<=n;++i)
	{
		A[i-1][0]=C[i-1][0]=1;
		for(int j=1;j<=i;++j)
			A[i][j]=A[i-1][j-1]*i%MOD,
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	}
	A[n][0]=C[n][0]=1;
}*/
void dfs(const int &i)
{
	if(i==n)
	{
		int num=0;
		for(int j=0;j^n;++j)
			if(!k[j]||num>=a[b[j]])++num;
		if(num<=n-m)ans=(ans+1)%MOD;
		return;
	}
	for(int j=0;j^n;++j)
	{
		if(!k1[j])
		{
			b[i]=j,k1[j]=1;
			dfs(i+1);
			k1[j]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s);
//	InitAC(n);
	for(int i=0;i^n;++i)scanf("%d",a+i);
//	std::stable_sort(a,a+n);
	for(int i=0;i^n;++i)
		k[i]=s[i]-'0';
	dfs(0);
	printf("%d",ans);
	return 0;
}
/*
3 2
101
1 1 2
*/
