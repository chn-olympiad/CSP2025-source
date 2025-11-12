# include <bits/stdc++.h>
using namespace std;
int t,n,ans;
struct stu{
	int x,y,z;
}s[100004];
void dfs(int now,int a,int b,int c,int tot){
	if(max(max(a,b),c)>n/2){
		return;
	}
	if(now==n+1){
		ans=max(ans,tot);
		return;
	}
	dfs(now+1,a+1,b,c,tot+s[now].x);
	dfs(now+1,a,b+1,c,tot+s[now].y);
	dfs(now+1,a,b,c+1,tot+s[now].z);
}
bool cmp(stu p,stu q){
	if(p.x!=q.x){
		return p.x>q.x;
	}
	return p.y>q.y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&s[i].x,&s[i].y,&s[i].z);
		}
		ans=0;
		if(n<=10){
			dfs(1,0,0,0,0);
			cout<<ans<<"\n";
		}else{
			sort(s+1,s+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=s[i].x;
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=s[i].y;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}