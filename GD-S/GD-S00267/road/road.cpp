#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct EDGE{
	int l,r,vis;
	int kkk;
}edge[1000010];
int ans;
int vili[20][10010],cnt;
int fa[10010];
int mtre[1000010],cntm;
int vil[20];
void ae(int a,int b,int c){
	edge[++cnt].l =a;
	edge[cnt].r =b;
	edge[cnt].vis =c;
}
int cmp(EDGE a,EDGE b){
	return a.vis <b.vis ;
}
int fin(int xx){
	if (fa[xx]==xx)	return xx;
	return fa[xx]=fin(fa[xx]);
}
void kus(){
	for (int i=1;i<=n;i++)	fa[i]=i;
	int tot=1,top=1;
	while (tot!=n){
		int x=fin(edge[top].l );
		int y=fin(edge[top].r );
		int z=edge[top].vis ;
		top++;
		if (x==y)	continue;
		fa[x]=y;
		tot++;
		ans+=z;
		mtre[++cntm]=top-1;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++){
		int a,b,c;
		scanf ("%d%d%d",&a,&b,&c);
		ae(a,b,c); 
	}
	sort(edge+1,edge+1+cnt,cmp);
	kus(); 
	for (int i=1;i<=k;i++){
		for (int j=0;j<=n;j++){
			scanf("%d",&vili[i][j]); 
		}
	}
	for (int i=1;i<=k;i++){
		for (int j=cntm;j>0;j--){
			int now=mtre[j];
			int ll=edge[now].l ;
			int rr=edge[now].r ;
			if (vil[i]){
				if (edge[now].vis >vili[i][ll]+vili[i][rr]){
					edge[now].vis =vili[i][ll]+vili[i][rr];
					vil[i]++;
					ans=ans-edge[now].vis +vili[i][ll]+vili[i][rr];
					vil[edge[now].kkk ]--;
					if (vil[edge[now].kkk ]==0)	ans-=vili[edge[now].kkk ][0];
					edge[now].kkk =i;
				}
				
			}
			else{
				if (edge[now].vis >vili[i][ll]+vili[i][rr]+vili[i][0]){
					edge[now].vis =vili[i][ll]+vili[i][rr];
					vil[i]++;
					ans=ans-edge[now].vis +vili[i][ll]+vili[i][rr]+vili[i][0];
					vil[edge[now].kkk ]--;
					if (vil[edge[now].kkk ]==0)	ans-=vili[edge[now].kkk ][0];
					edge[now].kkk =i;
				}	
			}
		}
	}
	cout<<ans;
	return 0;
}
