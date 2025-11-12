#include<bits/stdc++.h>
using namespace std;
const int N=1e4+20;
const int M=1e6+20;
int n,m,k,temp,ans;
int nbs[N],x,y,z,num,a[25][N];
int d[N];
bool boo[N],bo[N];
struct edge {
	int ed,next,w;
} b[M<<1];
void add(int x,int y) {
	num++;
	b[num].ed=y;
	b[num].w=z;
	b[num].next=nbs[x];
	nbs[x]=num;
}
int r(int u,int v){
	int t=1e9;
	for(int i=1;i<=k;i++)
		t=min(a[i][u]+a[i][v],t);
	return t;
}
void ans_2(){
	for(int i=0; i<=n; i++) d[i]=1e9;
	d[1]=0;
	int kk;
	for(int i=1; i<=n; i++) {
		kk=0;
		for(int j=1; j<=n; j++)
			if(!boo[j] && d[kk]>d[j]) kk=j;
		boo[kk]=1;
		for(int j=nbs[kk]; j; j=b[j].next) {
				
			x=b[j].ed;
			temp=min(b[j].w,r(kk,j));
			if(!boo[kk]&&d[x]>temp) {
				d[x]=temp;
//				dis[k]=min(dis[k],b[j].w);
			}
		}
	}
	ans=0;
	printf("\n");
	for(int i=1; i<=n; i++) ans+=d[i];
	printf("%d",ans);
	return ;
}
void ans_1() {
	for(int i=1; i<=m; i++) {
		scanf("%d%d%d",&x,&y,&z);
		add(x,y);
		add(y,x);
	}
	
	if(k<=5) {
		for(int i=1; i<=k; i++) {
			scanf("%d",&x);
			for(int j=1; j<=n; j++)
				scanf("%d",&a[i][j]);
		}
		ans_2();
		return ;
	}

	for(int i=0; i<=n; i++) {
		d[i]=1e9;
	}
	d[1]=0;

	for(int i=1; i<=n; i++) {
		k=0;
		for(int j=1; j<=n; j++)
			if(!boo[j] && d[k]>d[j]) k=j;
		boo[k]=1;
		for(int j=nbs[k]; j; j=b[j].next) {
			x=b[j].ed;
//			temp=min(,r(k,j));
			if(d[x]>b[j].w) {
				d[x]=b[j].w;
//				dis[k]=min(dis[k],b[j].w);
			}
		}
	}
	ans=0;
	printf("\n");
	for(int i=1; i<=n; i++) ans+=d[i];
	printf("%d",ans);
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	
	ans_1();
	return 0;
}
