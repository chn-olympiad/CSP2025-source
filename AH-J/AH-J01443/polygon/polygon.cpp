#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=998244353;
int n,m,s,a[5005];
void dfs(int cnt,int mx,int sum,int ans){
	if(cnt==n+1)
	{
		if(ans>=3 && sum>mx*2)
			s=(s+1)%N;
		return;
	}
	dfs(cnt+1,mx,sum,ans);
	dfs(cnt+1,max(mx,a[cnt]),sum+a[cnt],ans+1);
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(a[n]==1)
	{
		for(int l=3; l<=n; l++)
		{
			int cnt1=1,cnt2=1;
			for(int i=n; i>=n-l+1; i--)
				cnt1=cnt1*i%N;
			for(int i=1; i<=l; i++)
				cnt2=cnt2*i%N;
			s=(s+cnt1/cnt2)%N;
		}
		cout<<s;
		return 0;
	}
	dfs(1,0,0,0);
	cout<<s;
    return 0;
}
