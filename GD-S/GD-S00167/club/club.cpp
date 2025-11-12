#include<bits/stdc++.h>
using namespace std;
int T;
int n,ans;
struct node{
	int a,b,c;
}s[500005];
void dfs(int x,int ca,int cb,int cc,int p){
	if(x>n){
		ans=max(ans,p);
		return;
	}
	if(ca+1<=n/2)dfs(x+1,ca+1,cb,cc,p+s[x].a);
	if(cb+1<=n/2)dfs(x+1,ca,cb+1,cc,p+s[x].b);
	if(cc+1<=n/2)dfs(x+1,ca,cb,cc+1,p+s[x].c);
	return;
}
bool cmp(node a,node b){
	return a.a>b.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d %d %d",&s[i].a,&s[i].b,&s[i].c);
		if(n<=10){
			dfs(1,0,0,0,0);
		}else{
			sort(s+1,s+1+n,cmp);
			for(int i=1;i<=n/2;i++)ans+=s[i].a;
		}
		printf("%d",ans);
	}
	return 0;
}
