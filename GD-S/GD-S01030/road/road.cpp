#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k;
struct s{
	int to,from,v,next;
}a[1000006];
int top,head[100005];
void add(int x,int y,int v){
	top++;
	a[top].to=y;
	a[top].v=v;
	a[top].from=x;
	a[top].next=head[x];
	head[x]=top;
}
int c[15],cost[15][100005];
bool cmp(s a,s b){
	return a.v<b.v;
}
int tree[100005];
int findroot(int x){
	int root=x;
	while(tree[root])root=tree[root];
	while(tree[x]){
		int sum=tree[x];
		tree[x]=root;
		x=sum;
	}
	return root;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y,v;
		scanf("%d %d %d",&x,&y,&v);
		add(x,y,v);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&cost[i][j]);
		}
	}
	sort(a+1,a+1+top,cmp);
	int cnt=0;
	long long ans=0;
	for(int i=1;i<=top-k;i++){
		int fa,fb;
		fa=findroot(a[i].from);
		fb=findroot(a[i].to);
		if(fa!=fb){
			tree[fa]=fb;
			cnt++;
			ans=ans+a[i].v;
		}
		if(cnt==n-1)break;
	}
	printf("%lld",ans);
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
