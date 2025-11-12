#include<bits/stdc++.h>
#define rep(i,n,m) for(int i(n);i<=m;++i)
#define ref(i,n,m) for(int i(n);i>=m;--i)
using namespace std;
int mp[1<<21],a[500005],nxt[500005],pre[500005],dp[500005],maxn[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,tmp=0;
	cin>>n>>k;
	rep(i,1,n) cin>>a[i];
//	mp[0]=1;
	rep(i,1,n){
		tmp^=a[i];
//		cout<<tmp<<"\n";
		if(mp[tmp^k]||tmp==k) pre[i]=mp[tmp^k]+1;
		if(a[i]==k) pre[i]=i;
//		nxt[mp[tmp^k]]=(nxt[mp[tmp^k]]==0?i:nxt[mp[tmp^k]]);
//		if(nxt[mp[tmp^k]]==i) pre[i]=mp[tmp^k];
		mp[tmp]=i;
	}
	rep(i,1,n){
//		cout<<i<<" "<<pre[i]<<"\n";
		if(pre[i]!=0) 
		dp[i]=maxn[pre[i]-1]+1;
		maxn[i]=max(maxn[i-1],dp[i]);
	}
	cout<<maxn[n];
	return 0;
}
