#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5;
int n,ma,ans;
int a[N];
void solve(int i,int b,int l)
{
	if(b>=3&&l>=2*ma)
	{
		ans++;
	}
	for(int j=i+1;j<=n;j++)
	{
		b++;
		solve(j,b,a[j]+l);
		b--;
	}
 } 
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		solve(i,1,a[i]);
	}
	cout<<ans;
	return 0;
}
