//GZ-S00451 贵州师范大学云岩实验中学 闫峻浩
#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
struct no{
	int a,b,c;
}pe[100005];
bool cmp1(no x,no y){
	return x.a<y.a;
}
bool cmp2(no x,no y){
	return x.b<y.b;
}
void dfs(int now,int al,int bl,int cl,int ansi){
	if(now>n){
		ans=max(ans,ansi);
		return;
	}
	if(al<(n>>1)) dfs(now+1,al+1,bl,cl,ansi+pe[now].a);
	if(bl<(n>>1)) dfs(now+1,al,bl+1,cl,ansi+pe[now].b);
	if(cl<(n>>1)) dfs(now+1,al,bl,cl+1,ansi+pe[now].c);
	dfs(now+1,al,bl,cl,ansi);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&pe[i].a,&pe[i].b,&pe[i].c);
		}
		if(n==2){
			ans+=max({pe[1].a,pe[1].b,pe[1].c});
			ans+=max({pe[2].a,pe[2].b,pe[2].c});
			printf("%d\n",ans);
			continue;
		}
		else if(n<=30){
			dfs(1,0,0,0,0);
			printf("%d\n",ans);
			continue;
		}
		bool hh=1;
		for(int i=1;i<=n;i++){
			if(pe[i].c!=0){
				hh=0;
				break;
			}
		}
		if(hh==0){
			printf("%d\n",ans);
			continue;
		}
		bool hh1=1;
		for(int i=1;i<=n;i++){
			if(pe[i].b!=0){
				hh1=0;
				break;
			}
		}
		if(hh1==1){
			sort(pe+1,pe+n+1,cmp1);
			for(int i=1;i<=(n>>1);i++){
				ans+=pe[i].a;
			}
		}
		else{
			
		}
		printf("%d\n",ans);
	}
	return 0;
} 
