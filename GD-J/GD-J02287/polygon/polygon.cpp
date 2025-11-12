#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
ll n;
ll a[N];
bool cmp(ll x,ll y)
{
	return x>y;
}
ll ma;
ll s,sum;
ll ans;
void dfs(ll x)
{
	if(x>n)
	{
		if(sum>ma*2)ans++;
		return ;
	}
	if(s==0)ma=a[x];
	s++;
	sum+=a[x];
	dfs(x+1);
	s--;
	sum-=a[x];
	if(s==0)ma=0;
	dfs(x+1);
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	dfs(1);
	cout<<ans;
	return 0;
}

