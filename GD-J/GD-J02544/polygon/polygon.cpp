#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5005],ans,num,sum,maxa;
const int mod=998244353;
void dfs(int st)
{
	if(st>n){
		if(sum>maxa*2) ans++;
		return;
	}
	dfs(st+1);
	sum+=a[st];
	int tmp=maxa;
	maxa=max(maxa,a[st]);
	dfs(st+1);
	sum-=a[st];
	maxa=tmp;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}
