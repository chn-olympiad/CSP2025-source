//GZ-S00265 毕节梁才学校 杨文涯杰
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m,k;
struct E{
	LL dis;
	int x,y;
};
bool cmp(E x,E y){
	return x.dis<y.dis;
}
E d[1000000+10];
int p[10000+10];
int pt[20];
int a[20][10000+10];
int find(int x){
	if(p[x]!=x){
		int r=find(p[x]);
		p[x]=r;
	}
	return p[x];
}
int idx;
bool v;
LL kruskal(){
	LL ans=0;
	int cnt=0;
	for(int i=1;i<=m;i++){
		int x=d[i].x;
		int y=d[i].y;
		int z=d[i].dis;
		int px=find(x);
		int py=find(y);
		if(px!=py){
			p[px]=py;
			ans+=z;
			cnt++;
//			printf("==%d %d %d\n",x,y,z);
			if(cnt==n-1) break;
		}
	}
	return ans;
}
int x,y,z;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) p[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		d[++idx]=(E){z,x,y};
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&pt[i]);
		for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	}
	sort(d+1,d+idx+1,cmp);
//	if(k==0){
		printf("%lld",kruskal());
//	}else{
		
//	}
	return 0;
} 
