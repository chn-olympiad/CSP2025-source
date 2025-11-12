#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
const int N=1e5+10;
int T,n;
int a[N][3];
int ans,vis[5];
void dfs(int k,int sum){
	if(k>n){
		ans=max(ans,sum);
		return;
	}
	for(int i=0;i<=2;i++)
		if(vis[i]<n/2){
			vis[i]++;
			dfs(k+1,sum+a[k][i]);
			vis[i]--;
		}
		
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ans=0;
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)	cin>>a[i][0]>>a[i][1]>>a[i][2];
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}
