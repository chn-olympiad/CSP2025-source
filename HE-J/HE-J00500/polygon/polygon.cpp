#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int mod=998244353;
int n,a[N],cnt;
void dfs(int p,int sum,int maxn){
	if (p==n+1){
		if (sum>2*maxn)cnt++,cnt%=mod;
		return;
	}
	dfs(p+1,sum+a[p],max(maxn,a[p]));
	dfs(p+1,sum,maxn);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;++i){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<cnt;
}
