#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
const int N=5e3+10;
const int M=998244353;
int cnt;
int a[N];
void dfs(int step,int ans,int sum,int mx){
	if(step==n+1){
	
		if(ans>=3&&sum>2*mx){
			cnt=(cnt+1)%M;
		}
		return;	
	}
	dfs(step+1,ans+1,sum+a[step],a[step]);
	dfs(step+1,ans,sum,mx);
	
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(1,0,0,0);
	cout<<cnt%M;
return 0;
}
