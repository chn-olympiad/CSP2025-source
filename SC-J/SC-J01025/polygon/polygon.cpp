#include<bits/stdc++.h>
using namespace std;
#define int long long
int qm=998244353;
int n,maxn=INT_MIN,cnt;
const int N=5005;
int a[N],vis[N];
void dfs(int x,int sum,int mx,int la){
	if(x>n){
		return;
	}
	for(int i=la+1;i<=n;i++){
		if(!vis[a[i]]){
			if((sum+a[i])>max(mx,a[i])*2) cnt=(cnt+1)%qm;
			dfs(x+1,sum+a[i],max(mx,a[i]),i);
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		maxn=max(maxn,a[i]);
	}
	dfs(1,0,INT_MIN,0);
	cout<<cnt;
	return 0;
}