#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,r,ans,a[5010];
void dfs(int x,int mx,int s,int u,int t){
	if(x==r){
		if(s>mx*2){
			++ans;
			ans%=mod;
		}
		return ;
	}
	for(int i=t+1;i<=n;++i){
		dfs(x+1,max(u,int(a[i])),s+a[i],a[i],i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=3;i<=n;++i){
		r=i;
		dfs(0,0,0,0,0);
	}
	cout<<ans;
	return 0;
}
