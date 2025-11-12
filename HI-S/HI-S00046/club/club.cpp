#include<bits/stdc++.h>
using namespace std;
int t,n,hn,ans;
struct node{
	int a,b,c;
}s[100005];
void dfs(int cost,int m,int a,int b,int c) {
	for(int i=1;i<=3;i++){
		if(i==1&&a+1 <= hn){
			int costa=cost+s[m].a;
			if(n==m){
				ans=max(ans,costa);
				return;
			}
			dfs(costa,m+1,a+1,b,c);
		}
		if(i==2&&b+1 <= hn){
			int costb=cost+s[m].b;
			if(n==m){
				ans=max(ans,costb);
				return;
			}
			dfs(costb,m+1,a,b+1,c);
		}
		if(i==3&&c+1 <= hn){
			int costc=cost+s[m].c;
			if(n==m){
				ans=max(ans,costc);
				return;
			}
			dfs(costc,m+1,a,b,c+1);
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	scanf("%d",&t);
	while(t--){
		memset(s,0,sizeof(s));
		scanf("%d",&n);
		hn=n/2;ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
		}
		dfs(0,1,0,0,0);
		cout<<ans;
	} 
	return 0;
} 
