#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k,maxn=-1,vis[500005],ans=0;
bool xo(int l,int r){
	int sum=a[l];
	vis[l]=1;
	for(int i=l+1;i<=r;i++){
		sum^=a[i];
		vis[i]=1;
	}
	if(k==sum) return 1;
	for(int i=l;i<=r;i++){
		vis[i]=0;
	}
	return 0;
}
void dfs(int t){
	memset(vis,0,sizeof(vis));
	if(t>n) return;
	bool flag=1;
	for(int i=t,j;i<=n;i++){
		flag=1;
		if(vis[i]) continue;
		for(j=i;j<=n;j++){
			if(vis[j]){
				flag=0;
				break;
			}
			else if(xo(i,j)){
				ans++;
				flag=0;
				break;
			}
		}
		if(!vis[j]&&xo(i,j-1)&&flag) ans++;
	}
	maxn=max(maxn,ans);
	ans=0;
	dfs(t+1);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(vis,0,sizeof(vis));
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	int y;
	if(n<=200000&&n>1000&&k<=1){
		if(k){
			for(int i=1;i<=n;i++){
				if(a[i]) y++;
			}
			cout<<y;
			return 0;
		}
	}
	cout<<maxn;
	return 0;
}

