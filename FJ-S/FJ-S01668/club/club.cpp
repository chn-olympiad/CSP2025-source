#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int a,b,c;
}club[N];
int T,n,cnt[4],up_limit;
long long ans,step;
bool cmp(node x,node y){return x.a>y.a;}
void dfs(int i,int n,long long s){
	if(i==n+1){
//		printf("prepare done! now answer is %d,preparer is %d\n",ans,s);
		ans=(ans>=s?ans:s);
//		printf("and answer becomes %d\n",ans);
//		puts("----------NEXT----------");
		return;
	}
	for(int j=1;j<=3;j++){
		if(j==1 && cnt[j]<up_limit){
			cnt[j]++;
//			printf("student %d will join the club a\n",i);
			dfs(i+1,n,s+club[i].a);step++;
			cnt[j]--;
		}else if(j==2 && cnt[j]<up_limit){
			cnt[j]++;
//			printf("student %d will join the club b\n",i);
			dfs(i+1,n,s+club[i].b);step++;
			cnt[j]--;
		}else{
			if(cnt[j]<up_limit){
				cnt[j]++;
//				printf("student %d will join the club c\n",i);
				dfs(i+1,n,s+club[i].c);step++;
				cnt[j]--;
			}
		}
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d",&n);
		up_limit=n/2;
		memset(club,0,sizeof(club));
		bool twoo=true,threeo=true;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&club[i].a,&club[i].b,&club[i].c);
			if(club[i].b!=0)twoo=false;
			if(club[i].c!=0)threeo=false;
		}
		if(threeo && twoo){
			sort(club+1,club+1+n,cmp);
			for(int i=1;i<=up_limit;i++){
				ans=ans+club[i].a;
			}
			printf("%lld\n",ans);
		}else{
			dfs(1,n,0);
			printf("%lld\n",ans);
		}
	}
//	printf("the final step is %d",step);
	return 0;
} 
