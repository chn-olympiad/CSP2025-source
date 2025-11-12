#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,ans,cnt,x;
bool a[505];
char cc;
int b[505],c[505],dp[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	b[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>cc;
		if(cc=='1')a[i]=true;
		else a[i]=false;
		if(a[i])b[i]=b[i-1];
		else b[i]=b[i-1]+1;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0)x++;
	}
	if(b[n]==0)
	{
		ans=1;
		for(int i=n-x;i>=1;i--)
		{
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	sort(c+1,c+1+n);
	for(int i=1;i<=n;i++)
	{
		for(int j=n;j>=1;j--)
		{
			if(c[j]<=b[i])
			{
				dp[i]=dp[j-1]+dp[abs(j-i)];
			}
		}
	}
	for(int i=1;i<=n;i++)ans*=dp[i];
	cout<<ans;
	//for(int i=1;i<=n;i++)cout<<c[i];
	return 0;
}
/*


b[i]表示第i天    拒绝了    个人
 
100 47
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19

ans:161088479

5 3
11011
1 4 2 0 1
15423
15
S全部为1时，则无论什么顺序，必定能让所有人均被录用 
*/
