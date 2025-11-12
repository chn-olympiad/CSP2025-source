#include<bits/stdc++.h>
using namespace std;
int T,n,ans,cnt[3];
struct Node{
	int a,b,c,ma,maid;
}node[100005];
priority_queue<int> q1,q2,q3;
inline bool cmp(Node a,Node b){return a.ma>b.ma;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);ans=0;memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
	 		scanf("%d%d%d",&node[i].a,&node[i].b,&node[i].c);
			if(node[i].a>=node[i].b&&node[i].a>=node[i].c) node[i].ma=node[i].a,node[i].maid=0;
			else if(node[i].b>=node[i].a&&node[i].b>=node[i].c) node[i].ma=node[i].b,node[i].maid=1;
			else node[i].ma=node[i].c,node[i].maid=2;
		}
		sort(node+1,node+1+n,cmp);
		for(int i=1;i<=n;i++){
			ans+=node[i].ma;
			if(node[i].maid==0) q1.push(max(node[i].b,node[i].c)-node[i].ma);
			else if(node[i].maid==1) q2.push(max(node[i].a,node[i].c)-node[i].ma);
			else q3.push(max(node[i].a,node[i].b)-node[i].ma);
			if(++cnt[node[i].maid]>(n/2)){
				cnt[node[i].maid]--;
				if(node[i].maid==0) ans+=q1.top(),q1.pop();
				else if(node[i].maid==1) ans+=q2.top(),q2.pop();
				else ans+=q3.top(),q3.pop();
			}
		}
		printf("%d\n",ans);
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		while(!q3.empty()) q3.pop();
	}
}
