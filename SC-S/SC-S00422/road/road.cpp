#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct Node{
	int x,y;long long w;
}x[2001000];
long long a[20][10100];
bool cmp(Node a,Node b){
	return a.w<b.w;
}
int fa[2001000];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y) return 0;
	else{
		fa[y]=x;
		return 1;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i <= m;i++){
		cin>>x[i].x>>x[i].y>>x[i].w;
	}
	for(int i=1;i <= n+k;i++) fa[i]=i;
	sort(x+1,x+m+1,cmp);
	if(!k){
		long long ans=0;
		for(int i=1;i <= m;i++){
			if(merge(x[i].x,x[i].y)){
				ans+=x[i].w;
			}
		}
		cout<<ans;
	}else if(n<=1000&&k<=5){
		for(int i=1;i <= k;i++){
			for(int j=0;j <= n;j++){
				cin>>a[i][j];
			}
		}
		long long an=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i < (1<<k);i++){
			for(int j=1;j <= n+k;j++) fa[j]=j;
			int S=i,g=0;
			long long ans=0;
			int e=m;
			while(S){
				g++;
				if(S&1){
					ans+=a[g][0];
					for(int j=1;j <= n;j++){
						x[++e]={g+n,j,a[g][j]};
					}
				}
				S>>=1;
			}
			sort(x+1,x+e+1,cmp);
			for(int j=1;j <= e;j++){
				if(merge(x[j].x,x[j].y)){
					ans+=x[j].w;
				}
			}
			an=min(an,ans);
		}
		cout<<an;
	}else{
		for(int i=1;i <= k;i++){
			for(int j=0;j <= n;j++){
				cin>>a[i][j];
			}
		}
		long long ans=0;
		for(int i=1;i <= m;i++){
			if(merge(x[i].x,x[i].y)){
				ans+=x[i].w;
			}
		}
		cout<<ans;
	}
	
	return 0;
}
/*
列一下计划
4:30-5:00 T3
5:00-6:00 T2
6:00-6:30 检查
*/