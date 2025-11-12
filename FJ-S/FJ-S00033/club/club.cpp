#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001][3],ans,aa,bb,cc;
void dfs(int x,int y){
	if(x==n){
		ans=max(ans,y);
		return;
	}
	if(aa+1<=n/2){
		aa++;
		dfs(x+1,y+a[x+1][0]);
		aa--;
	}
	if(bb+1<=n/2){
		bb++;
		dfs(x+1,y+a[x+1][1]);
		bb--;
	}
	if(cc+1<=n/2){
		cc++;
		dfs(x+1,y+a[x+1][2]);
		cc--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		aa=0;
		bb=0;
		cc=0;
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i][0]);
			scanf("%d",&a[i][1]);
			scanf("%d",&a[i][2]);
		}
		dfs(0,0);
		cout<<ans<<endl;
	}
	return 0;
}



