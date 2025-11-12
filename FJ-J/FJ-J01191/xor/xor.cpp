#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
int n,k,ans=0,a[maxn];
bool vis[maxn];
void dfs(int l,int r,long long sum,int cnt){
	if(r == n+1){
		ans = max(cnt,ans);
		return;
	}
	if(sum == k){
		cout << l << " " << r  << " " << cnt+1 << endl;
		dfs(r+1,r+1,0,cnt+1);
	}
	for(int i=l;i<=n;i++){
		if(vis[i] == 0){
			vis[i] = 1;
			dfs(l,i,sum^a[i],cnt);
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(vis,0,sizeof(vis));
	scanf("%d%d",&n,&k);
	int tmp=0,s=0,t=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i] == 0) s++;
		if(a[i] == a[i-1]){
			tmp++;
		}
		else{
			t+=(tmp/2);
			tmp = 0;
		}
	}
	if(k == 0){
		printf("%d",s+tmp);
		return 0;
	}
	dfs(1,1,0,0);
	printf("%d",ans);
	return 0;
}
