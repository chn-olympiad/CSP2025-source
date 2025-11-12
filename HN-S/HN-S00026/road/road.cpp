#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int sum,number;
struct eger{
	int u,v,w;
};
int num=0;
eger mapl[900005];
bool camp(eger a,eger b){
	return a.w<b.w;
}
int tree[900005];
int finds(int x){
	if(tree[x]!=x) tree[x]=finds(tree[x]);
	return tree[x];
}
void unio(int x,int y){
	int rootX=finds(x);
	int rootY=finds(y);
	if(rootX!=rootY){
		tree[rootX]=tree[rootY];
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;++i) tree[i]=i;
	for(int i=1;i<=m;++i){
		num++;
		scanf("%d %d %d",&mapl[num].u,&mapl[num].v,&mapl[num].w);
	}
	for(int i=1;i<=k;++i){
		int c;
		scanf("%d",&c);
		int H=num;
		int p=0;
		for(int j=1;j<=n;++j) {
			num++;
			scanf("%d",&mapl[num].w);
			mapl[num].u=j;
			mapl[num].v=i;
			if(i==j) p=mapl[num].w;
			mapl[num].w+=c;
			}
		for(int j=1;j<=n;++j){
			H++;
			mapl[H].w+=p;
		}
	}
	sort(mapl+1,mapl+1+num,camp);
	int number=0;
	for(int i=1;i<=num;++i){
		if(finds(mapl[i].u)!=finds(mapl[i].v)){
			unio(mapl[i].u,mapl[i].v);
			sum+=mapl[i].w;
			number++;
		}
		if(number==n-1){
			printf("%d",sum);
			return 0;
		}
	}
	return 0;
}

