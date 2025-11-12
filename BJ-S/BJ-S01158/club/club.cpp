#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T;
int n;
ll ans;
int fl[4];
int a[100001][4];
void dfs(int lv,ll v){
	if(lv==n+1){
		ans=max(ans,v);
		return;
	}
	for(int i=1;i<=3;i++){
		if(fl[i]<n/2){
			fl[i]++;
			//cout<<a[lv][i]<<" "<<lv+1<<" "<<v+a[lv][i]<<endl;
			dfs(lv+1,v+a[lv][i]);
			fl[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		dfs(1,0);
		printf("%lld\n",ans);
	}
	return 0;
}
