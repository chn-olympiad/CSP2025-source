#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int unsigned long long
int n,m,k;
struct road{
	int u,v,w;
};
road a[10000001];
int f[11][10001],map[10001][10001];
int fa[10001],num;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
int fi(int x){
	while(fa[x]!=x)x=fa[x];
	return x;
}
void comb(int x,int y){
	x=fi(x);
	y=fi(y);
	fa[y]=x;
	return;
}
bool cmp(road x,road y){
	return x.w<y.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			map[j][i]=2e9+1;
		}
	}
	for(int i=1;i<=m;i++){
		a[i].u=read();
		a[i].v=read();
		a[i].w=read();
		if(a[i].u>a[i].v)swap(a[i].u,a[i].v);
		map[a[i].u][a[i].v]=a[i].w;
	}
	unsigned long long sum=0;
	if(k==0){
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=m;i++){
			if(fi(a[i].u)!=fi(a[i].v)){
				sum+=a[i].w;
				comb(a[i].u,a[i].v);
			}
		}
		printf("%d",sum);
		return 0;
	}
	for(int i=1;i<=k;i++){
		int x;
		x=read();
		for(int j=1;j<=n;j++){
			f[i][j]=read()+x;
			for(int l=1;l<j;l++){
				if(map[l][j]>f[i][j]-x+f[i][l]){
					map[l][j]=f[i][j]-x+f[i][l];
				}
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(map[j][i]<2e9+1){
				cnt++;
				a[cnt].u=j;
				a[cnt].v=i;
				a[cnt].w=map[j][i];
			} 
		}
	}
	sort(a+1,a+cnt+1,cmp);
//	for(int i=1;i<cnt;i++)printf("%d ",a[i].w);
//	cout<<endl;
	for(int i=1;i<=cnt;i++){
		if(fi(a[i].u)!=fi(a[i].v)){
			sum+=a[i].w;
			comb(a[i].u,a[i].v);
			num++;
		}
		if(num==n-1)break;
	}
	printf("%d",sum);
	return 0;
}
