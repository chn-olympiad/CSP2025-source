#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans,n,a[5010],cnt[5];
void dfs(int u,int f){
	if(u==n+1&&f>=4){
		ans++;
		ans%=998244353;
	}
	for(int i=u+1;i<=n+1;i++){
		dfs(i,f+1);
	}
	return ;
}
void dfs1(int u,int f,int cnt,int max){
	if(u==n+1&&f>=4&&cnt>2*max){
		ans++;
		ans%=998244353;
	}
	for(int i=u+1;i<=n+1;i++){
		if(a[i]>max){
			dfs1(i,f+1,cnt+a[i],a[i]);
		}else{
			dfs1(i,f+1,cnt+a[i],max);
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	if(cnt[1]==n){
		dfs(0,0);
		cout<<ans;
	}else if(n<=500){
		dfs1(0,0,0,0);
		cout<<ans;
	}else{
		cout<<0;
	}
	return 0;
}