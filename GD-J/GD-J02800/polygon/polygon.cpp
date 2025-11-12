#include<iostream>
#include<cstring>
#include<cstdio>
#define mod 998244353
#define int long long
using namespace std;
int a[114514],C[5002][5002];
int n,m,i,j,k,jieshou=0,maxai=-1919810,sum=0,result=0,jjj=0;
int dfs(int k, int chased,int tot, int bigst)
{
	if (k == n+1 or chased == i) 
	{
		if (chased < i) return 0;
		if (tot > 2*bigst){
		result ++;
		result %= mod;
		}
	}else{
		jjj=0;
		jjj=dfs(k+1, chased+1,tot + a[k] , max(bigst, a[k]));
		jjj=dfs(k+1, chased,tot , bigst);  
	}
	return 0;
}
signed main()
{
	n=m=i=j=k=0;
	memset(a,0,sizeof(a));
	memset(C,0,sizeof(C));
	freopen("polygon3.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (i=1;i<=n;i++)
		{
		cin >> a[i];
		maxai=max(maxai,a[i]);
		}
	if (maxai == 1)
	{
		C[1][1]=1;
		for (i=2;i<=n;i++)
			{
			for (j=1;j<=i;j++){
				C[i][j] = C[i-1][j]+C[i-1][j-1];
				C[i][j] %= mod; 
			}
				
			}
		for (i=3;i<=n;i++) 
		{
			sum = sum + C[n][i] % mod;
			sum %= mod;
		}
		cout << sum;
	}else {
		for (i=3;i<=n;i++) 
		{
			result =0;
			jieshou=dfs(1,0,0,0);
			sum = sum + result % mod;//dfs(k, tot, bigst)
			sum %= mod;
		//	cout << result << endl;
		}
		cout << sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
(a+b) mod c = amodc + bmodc   modc
ab mod c = amodc * bmodc modc 
*/
