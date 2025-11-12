#include<bits/stdc++.h>
#define int long long
using namespace std;
const int zzz=252525;
const int mod=998244353;
bool cmp(int a,int b){return a>b;}
int n,a[zzz],p[zzz],ans,big;
vector <int> v;
void dfs(int i,int s,int t)
{
	if(i==n+1) return ;
	if(s>big and t>=3) ans++,ans%=mod;
	dfs(i+1,s+a[i],t+1);
	dfs(i+1,s,t);
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int j=1;j<=n;j++)
	{
		big=a[j]*2;
		dfs(j+1,a[j],1);
	}
	cout<<ans*2;
	return 0;
}
