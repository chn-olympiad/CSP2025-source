#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
const int N=5e3+3;
const int MOD=998244353;
int a[N];
int ans;
void dfs(int id,int cnt,int sum,int maxx){
	if(id>n){
		if(cnt>=3 && sum>maxx*2)ans++;
		return;
	}
	if(cnt+(n-id+1)<3)return;
	dfs(id+1,cnt+1,sum+a[id],max(maxx,a[id]));
	dfs(id+1,cnt,sum,maxx);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0,0,0);
	cout<<ans%MOD;
	
	return 0;
}
