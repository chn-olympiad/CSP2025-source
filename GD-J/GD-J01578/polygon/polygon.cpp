#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,ans,a[N],e[N];
bool vis[N];
void dfs(int s,int now,int sum,int maxx,bool flag){
	if(s>=3 && sum>2*maxx && flag){
		ans++;
	}
	if(now>=n){
		return;
	}
	if(!vis[now]){
		vis[now]=1;
		dfs(s+1,now+1,sum+a[now+1],max(maxx,a[now+1]),1);
		vis[now]=0;
	}
	dfs(s,now+1,sum,maxx,0);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	/*
	Too dificult,I want to sleep...zz ZZZ
	freeeeeeeeeeeeeeeeeopen("zhanshuangpunishing.in","r",stdin);
	How to debug?QWQ......30min,I make it!!!But,O(2^n) QWQ++
	oOoOooOOOooOO orz
	CaCO3 orz
	RP+=0x3f3f3f3f;
	*/
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,-1,0);
	cout<<ans;
	return 0;
}
