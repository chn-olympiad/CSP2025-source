#include<bits/stdc++.h>
using namespace std;
const int N=5001,mod=998244353;
int n,a[N],ans;
void dfs(int now,bool pd,int s,int zd){
	if(now>n)return;
	zd=max(zd,a[now]);
	if(pd==1)s+=a[now];
	if(s>zd*2){
		ans++;
		ans=ans%998244353; 
	}
	dfs(now+1,1,s,zd);
	dfs(now+1,0,s,zd);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	dfs(1,1,0,0);
	cout<<ans;
	return 0;
}
