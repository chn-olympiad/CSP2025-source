#include <bits/stdc++.h>
#define start_code signed main(){
#define stop_code return 0;}
#define elif else if
#define infile(x) freopen(#x".in","r",stdin)
#define outfile(x) freopen(#x".out","w",stdout)
#define ansfile(x) freopen(#x".ans","w",stdout)
#define openfile(x) (infile(x),outfile(x))
#define fastio() (ios::sync_with_stdio(0),cin.tie(0),cout.tie(0))
#define powi2(x) ((x)*(x))
#define pow2i(x) (1<<(x))
#define int long long
using namespace std;
const int N = 5005,MOD = 998244353;
int n,a[N],ans;
//bitset<N> f;
void dfs(int dep,int sum,int maxx,int num)
{
	if (dep > n)
	{
		if (sum > maxx*2) (++ ans) %= MOD;
		return ;
	}
	if (num==0 && dep==n-2)
	{
		if (a[n]+a[n-1]+a[n-2] > max({a[n],a[n-1],a[n-2]})*2) (++ ans) %= MOD;
		return ;
	}
	if (num==1 && dep==n-1)
	{
		if (a[n]+a[n-1]+sum > max({a[n],a[n-1],maxx})*2) (++ ans) %= MOD;
		return ;
	}
	if (num==2 && dep==n)
	{
		if (a[n]+sum > max(a[n],maxx)*2) (++ ans) %= MOD;
		return ;
	}
	dfs(dep+1,sum,maxx,num);
	dfs(dep+1,sum+a[dep],max(maxx,a[dep]),num+1);
}
start_code
openfile(polygon);
cin>>n;
for (int i = 1;i <= n;i ++) cin>>a[i];
dfs(1,0,0,0);
cout<<ans;
stop_code
/*
const int N = 5005,MOD = 998244353;
int n,a[N],ans,m,si,maxx;
bitset<N> f;
void dfs(int dep,int sum)
{
	if (dep > m)
	{
		if (sum > maxx) throw sum;
		return ;
	}
	if ()
}

cin>>n;
for (int i = 1;i <= n;i ++) cin>>a[i];
sort(a+1,a+n+1);
for (int i = 3;i <= n;i ++)
{
	m = i,maxx = a[i],f.reset();
	for (int j = 2;j < i;j ++)
	{
		si = j;
	}
}
*/
