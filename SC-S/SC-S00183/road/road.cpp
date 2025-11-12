#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N=10000;

int rd1(){
	int a=0,f=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-f;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=a*10+c-'0';
		c=getchar();
	} 
	return a*f;
}

ll rd2(){
	ll a=0,f=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-f;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=a*10+c-'0';
		c=getchar();
	} 
	return a*f;
}

struct Lu{
	int a;
	int b;
};

int n,m,k;
Lu a[N*N+5];
ll f[N+5][N+5];
int l;
int fa[N+15];
ll ans;
ll b[N+5];

bool cmp(Lu x,Lu y){
	return f[x.a][x.b]<f[y.a][y.b];
}

int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}

void st(){
	int x=0,y=0;
	for(int i=1;i<=l;i++){
		x=find(a[i].a);
		y=find(a[i].b);
		if(x==y){
			continue;
		}
		fa[x]=y;
		ans+=f[a[i].a][a[i].b];
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd1(),m=rd1(),k=rd1();
	int u,v;
	ll w;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=0x3f3f3f3f3f3f3f3f;
		}
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		u=rd1(),v=rd1(),w=rd2();
		f[v][u]=f[u][v]=min(f[u][v],w);
	}
	ll c;
	for(int i=1;i<=k;i++){
		c=rd2();
		for(int j=1;j<=n;j++){
			b[j]=rd2();
			for(int k=1;k<j;k++){
				f[j][k]=f[k][j]=min(f[j][k],b[j]+b[k]+c);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(f[i][j]!=0x3f3f3f3f3f3f3f3f){
				l++;
				a[l].a=i;
				a[l].b=j;
			}
		}
	}
	sort(a+1,a+l+1,cmp);
	st();
	printf("%lld\n",ans);
	return 0;
}
