#include<bits/stdc++.h> 
using namespace std;
int T,n,x[210][3],ans;
struct nn{int a,b,c,n,m;};
void bfs(){
	queue<nn> q;
	q.push({0,0,0,1,0});
	while(!q.empty()){
		nn t=q.front();
		q.pop();
		if(t.n>n&&t.a<=n/2&&t.b<=n/2&&t.c<=n/2)ans=max(ans,t.m);
		if(t.n<=n&&t.a<=n/2&&t.b<=n/2&&t.c<=n/2){
			q.push({t.a+1,t.b,t.c,t.n+1,t.m+x[t.n][0]});
			q.push({t.a,t.b+1,t.c,t.n+1,t.m+x[t.n][1]});
			q.push({t.a,t.b,t.c+1,t.n+1,t.m+x[t.n][2]});
		}
	}
	return;
} 
//Ren5Jie4Di4Ling5%
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d%d%d",&x[i][0],&x[i][1],&x[i][2]);
		bfs();
		printf("%d\n",ans);
	}
	return 0;
}
