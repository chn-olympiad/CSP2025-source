#include<bits/stdc++.h>
using namespace std;
int n,a[5005],x;
long long ans;
void dfs(int k,int p,int ma,int sum)
{
	if(k==x)
	{
		if(sum>2*ma)
			ans+=1;
		return;
	}
	if(p==n) return;
	if(n-p+1<k) return;
	dfs(k+1,p+1,max(ma,a[p+1]),sum+a[p+1]);
	dfs(k,p+1,ma,sum);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(x=3;x<=n;x++)
		dfs(0,0,0,0);
	cout << ans;
	return 0;
}
