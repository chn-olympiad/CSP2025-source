//GZ-J00196 贵阳市花溪区剑桥学校（初中部） 戚星汉
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
struct stu{
	int a,b,c;
}p[100005];
int t,n,ans,tmp;
bool vis[100005];
void dfs(int tot,int x,int y,int z,int cnt){
	if(cnt==n){
		ans=max(ans,tot);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(x>0){
				dfs(tot+p[i].a,x-1,y,z,cnt+1);
			}
			if(y>0){
				dfs(tot+p[i].b,x,y-1,z,cnt+1);
			}
			if(z>0){
				dfs(tot+p[i].c,x,y,z-1,cnt+1);
			}
			tmp++;
			vis[i]=0;
		}
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		tmp=0;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			vis[i]=0;
		}
		dfs(0,n/2,n/2,n/2,0);
		cout<<ans<<endl;
	}
	return 0;
}
