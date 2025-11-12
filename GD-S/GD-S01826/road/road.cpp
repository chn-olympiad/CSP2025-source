#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+10,M=2e6+10;
int n,m,k,tg[M],hd[M],nxt[M],c[N],a[15][N];
int cnt,w[M],fa[N],ans;
struct NN{
	int x,y,z;
}s[M];
int getfa(int x){
	if(fa[x]==0){
		return x;
	}else{
		return fa[x]=getfa(fa[x]);
	}
}
void me(int x,int y){
	int xx=getfa(x),yy=getfa(y);
	if(xx!=yy){
		fa[xx]=yy;
	}
}
bool fam(int x,int y){
	int xx=getfa(x),yy=getfa(y);
	return xx!=yy;
}
void link(int x,int y,int z){
	tg[++cnt]=y;
	nxt[cnt]=hd[x];
	hd[x]=cnt;
	w[cnt]=z;
}
bool cmp(NN x,NN y){
	return x.z<y.z;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("road1.in","r",stdin);
//	freopen("road3.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>s[i].x>>s[i].y>>s[i].z;
	}	
	sort(&s[1],&s[(m+1)*2],cmp);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int ss=0;
	for(int i=1;i<=m*2 and ss<=n-1;i++){
		if(fam(s[i].x,s[i].y)){
			me(s[i].x,s[i].y);
			ans+=s[i].z;
			ss++;
		}
	}
	cout<<ans;
	
	

	return 0;
}
/*

4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

*/ 
