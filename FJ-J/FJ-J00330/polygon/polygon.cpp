#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int num[5005];
int n;
long long ans;
void dfs(int sum,int x,int maxn,int vis)//2^n solve
{
	if(x>n&&(vis>=3)&&(sum>(maxn*2)))
	{
		ans++;
		ans%=mod;
		return;
	}
	if(x>n)return;
	dfs(sum+num[x],x+1,max(maxn,num[x]),vis+1);
	dfs(sum,x+1,maxn,vis);
	return;
}
bool flag = true;
inline long long fp(long long a,long long b)
{
	long long res = 1;
	while(b)
	{
		if(b%2)
		{
			res*=a;
			res%=mod;
		}
		a*=a;
		a%=mod;
		b>>=1;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	freopen("polygon.in","r",stdin);
 	freopen("polygon.out","w",stdout);
 	cin >> n;
 	for(int i = 1;i<=n;i++)
 	{
 		cin >> num[i];
 		if(num[i]>1)flag = false;
 	}
 	if(flag)
 	{
 		cout << (fp(2,n)-2*n+mod)%mod;
 	}
 	else
	{
 		dfs(0,1,0,0);
 		cout << ans;
 	}
	return 0;
}

