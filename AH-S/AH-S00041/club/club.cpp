#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int v,a,b,c,num;
};
int T,n,A[N][4],mx;
queue <node> q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		mx=0;
		memset(A,0,sizeof(A));
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%d%d%d",&A[i][1],&A[i][2],&A[i][3]);
		}
		q.push({A[1][1],1,0,0,1});
		q.push({A[1][2],0,1,0,1});
		q.push({A[1][3],0,0,1,1});
		while(!q.empty()){
			node now=q.front();
			q.pop();
			mx=max(mx,now.v);
			//printf("%d %d %d %d %d\n",now.v,now.a,now.b,now.c,now.num);
			if(now.a+1<=n/2){
				q.push({now.v+A[now.num+1][1],now.a+1,now.b,now.c,now.num+1});
			}
			if(now.b+1<=n/2){
				q.push({now.v+A[now.num+1][2],now.a,now.b+1,now.c,now.num+1});
			}
			if(now.c+1<=n/2){
				q.push({now.v+A[now.num+1][3],now.a,now.b,now.c+1,now.num+1});
			}
		}
		printf("%d\n",mx);
	}
}
