#include<bits/stdc++.h>
#define endl '\n'
#define LX long long
const LX MOD = 998244353; 
using namespace std;
LX n,s = 0;
vector<LX> a(5010,0);
LX dfs(LX b,LX m,LX ss,LX cnt)//b 边  m 最大 ss 总和  cnt便利到的边 
{
	if(!b)
	{
		if(2*m<ss) return 1;
		else	   return 0;
	}
	int sum = 0;
	for(int i=cnt;i<=n-cnt;i++)
	{
		sum += dfs(b-1,max(a[i],m),ss+a[i],cnt+1);
	}
	return sum%MOD;
} 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=3;i<=n;i++)
	{
		s+=dfs(i,-1,0,1);
	}
	cout << s%MOD << endl;
	return 0;
}
