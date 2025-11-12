#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int x,sum,vis1,vis2,vis3;
};
int t,n,vis[N],a[N][4];
int bfs(){
	int ans=0;
	queue<node>q;
	q.push({0,0,0,0,0});
	while(!q.empty()){
		node t=q.front();q.pop();
		//printf("%d %d %d %d %d\n",t.x,t.sum,t.vis1,t.vis2,t.vis3);
		if(t.x>n){
			ans=max(ans,t.sum);
			continue;
		}
		if(t.vis1<n/2){ 
			q.push({t.x+1,t.sum+a[t.x+1][1],t.vis1+1,t.vis2,t.vis3});
		}
		if(t.vis2<n/2){
			q.push({t.x+1,t.sum+a[t.x+1][2],t.vis1,t.vis2+1,t.vis3});
		}
		if(t.vis3<n/2){
			q.push({t.x+1,t.sum+a[t.x+1][3],t.vis1,t.vis2,t.vis3+1});
		}
	}
	return ans;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)scanf("%d",&a[i][j]);
		}
		printf("%d\n",bfs());
		memset(a,0,sizeof a);
	}
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
