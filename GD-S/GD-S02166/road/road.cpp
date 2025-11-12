#include<bits/stdc++.h>
using namespace std;
int const M=2e6+100;
int n,m,k,ll; 
int pre[10101];
int kk[10][10101];
long long ans;
struct bian{
	int next;
	long long w;
	int to;
	bool operator<(const bian &x)const{ 
		return w>x.w;
	}
}l[M],g;
priority_queue<bian>q;
bool b[10101];
void jb(int x,int y,long long w){
	ll++;
	l[ll].next=pre[x];
	l[ll].to=y;
	l[ll].w=w;
	pre[x]=ll;
	return;
}
int main(){
//	cout<<M;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	int x,y,w;
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&x,&y,&w);
		jb(x,y,w);
		jb(y,x,w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&kk[i][0]);
		for(int j=1;j<=n;j++){
			scanf("%d",&kk[i][j]);
		}
	}
	b[1]=1;
	for(int i=pre[1];i!=0;i=l[i].next){
		q.push(l[i]);
	}
	while(!q.empty()){
		g=q.top();
		q.pop();
		if(b[g.to])continue;
		ans+=g.w;
//		cout<<g.w<<" "<<g.to<<endl;
		b[g.to]=1;
		for(int i=pre[g.to];i!=0;i=l[i].next){
			int to=l[i].to;
			if(!b[to])q.push(l[i]);
		}
	}
	printf("%lld",ans);
	return 0;
}
/*
4 6 0
1 2 168
2 3 20
4 3 10
4 1 5
1 3 1
2 4 6
*/

