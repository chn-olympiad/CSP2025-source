#include<bits/stdc++.h>
using namespace std;
int x[100005][5],y[100005],ans,ans2;
void dfs(int i,int a,int b,int c,int cnt,int m){
	if(i==m+1){
		ans=max(ans,cnt);
		return;
	}
	if(a<m/2)dfs(i+1,a+1,b,c,cnt+x[i][1],m);
	if(b<m/2)dfs(i+1,a,b+1,c,cnt+x[i][2],m);
	if(c<m/2)dfs(i+1,a,b,c+1,cnt+x[i][3],m);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n,flag=1;
		ans=0;ans2=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&x[i][1],&x[i][2],&x[i][3]);
			if(x[i][2]!=0||x[i][3]!=0)flag=0;
			y[i]=x[i][1];
		}
		if(flag){
			sort(y+1,y+1+n);
			for(int i=n;i>n/2;i--)ans2+=y[i];
			printf("%d\n",ans2);
			continue;
		}
		dfs(0,0,0,0,0,n);
		printf("%d\n",ans);
	}
	return 0;
}
