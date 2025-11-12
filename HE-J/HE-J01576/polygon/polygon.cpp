#include<bits/stdc++.h>
#define int long long
using namespace std;
const int it=998244353;
int n,m,ans;
int v[5005];
bool st[5005];
int num,sum;
void dfs(int s){
	for(int i=s;i<=n;i++){
		if(num>=3&&sum>m){
			ans=(ans+1)%it;
		}
		if(st[i]) continue;
		st[i]=1;num++;sum+=v[i];
		dfs(i);
		st[i]=0;num--;sum-=v[i];
	}
	return ;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		m=max(m,v[i]);
	}m*=2;
	if(n==3){
		cout<<1;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
