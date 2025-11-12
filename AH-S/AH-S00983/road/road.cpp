#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
bool fA=1;
int ans;
int c[15];
int a[15][10055];
int fa[10055];
struct edge{
	int u,v,w;
}e[5000055];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
void read(int &x){
	int f=1;
	x=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	x*=f;
}
int find(int x){
	if(x==fa[x]){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void solve0(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(e+1,e+m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(find(e[i].u)!=find(e[i].v)){
			ans+=e[i].w;
			fa[find(e[i].u)]=find(e[i].v);
			cnt++;
			if(cnt==n-1){
				break;
			}
		}
	}
	cout<<ans;
	return ;
}
void solveA(){
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			e[++m]=(edge){n+i,j,a[i][j]};
		}
	}
	n+=k;
	solve0();
	return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);read(m);read(k);
	for(int i=1;i<=m;i++){
		read(e[i].u);
		read(e[i].v);
		read(e[i].w);
	}
	if(k==0){
		solve0();
		return 0;
	}
	for(int i=1;i<=k;i++){
		read(c[i]);
		if(c[i]){
			fA=0;
		}
		bool fAA=0;
		for(int j=1;j<=n;i++){
			read(a[i][j]);
			if(!a[i][j]){
				fAA=1;
			}
		}
		fA&=fAA;
	}
	if(fA){
		solveA();
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
