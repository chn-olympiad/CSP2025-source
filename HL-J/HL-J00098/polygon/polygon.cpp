//待优化，样例4超时 
#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n;
int a[5005];
int ans=0;
void dfs(int tot,int cur,int curd,int sum,int maxx){
	if(cur==tot){
		if(sum>maxx*2){
			ans++;
			ans%=MOD;
			return;
		}
	}else if(cur!=tot){
		cur++;
		for(int i=curd+1;i<=n;i++){
			dfs(tot,cur,i,sum+a[i],max(maxx,a[i]));
		}
	}
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		dfs(i,0,0,0,0);
	}
	cout<<ans;
	return 0;
}

