#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,s[5001],l[5001],ans,maxn;
void dfs(int step,int mx,int sum,int res){
	if(!step){
		if(sum>l[mx]&&res>2)ans++;
		return;
	}
	if(s[step-1]+sum>l[mx])dfs(step-1,mx,sum,res);
	dfs(step-1,mx,sum+l[step],res+1);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>l[i],s[i]=s[i-1]+l[i],maxn=max(maxn,l[i]);
	sort(l+1,l+n+1);
	for(int i=1;i<=n;i++){
		if(s[i-1]<=l[i])continue;
		dfs(i-1,i,0,1);
	}
	cout<<ans;
} 
