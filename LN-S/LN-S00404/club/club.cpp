#include <bits/stdc++.h>
using namespace std;
int n,T;
int a[100010][3],mx,cnt[3];
void dfs(int x,int ans){
	if(x==n+1){
		mx=max(mx,ans);
		return;
	}
	for(int i=0;i<=2;i++){
		if(cnt[i]>=n/2) continue;
		cnt[i]++;
		dfs(x+1,ans+a[x][i]);
		cnt[i]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		mx=0;
		if(n<=30) dfs(1,0);//1-8 40
		else{
			for(int i=1;i<=n;i++)
				mx+=max(max(a[i][0],a[i][1]),a[i][2]);
		}
		printf("%d\n",mx);
	}
	return 0;
}

