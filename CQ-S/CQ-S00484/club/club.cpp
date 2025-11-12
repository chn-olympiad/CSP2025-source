#include<bits/stdc++.h>
using namespace std;
const int N=1e2+6;
int a[N],b[N],c[N],f[N][N/2][N/2][N/2];
int t,n,tn,ans;
int max(int a,int b){if(a<b) a=b;return a;}
int dfs(int id,int al,int bl,int cl){
	//cout<<id<<' '<<f[id-1][al+1][bl][cl]<<' '<<al<<' '<<bl<<' '<<cl<<'\n';
	if(!id){return 0;}
	int xsm=0;
	if(al<tn){
		if(f[id-1][al+1][bl][cl]) xsm=f[id-1][al+1][bl][cl]+a[id];
		else xsm=dfs(id-1,al+1,bl,cl)+a[id];
	}
	if(bl<tn){
		if(f[id-1][al][bl+1][cl])
		xsm=max(xsm,f[id-1][al][bl+1][cl]+b[id]);
		else xsm=max(xsm,dfs(id-1,al,bl+1,cl)+b[id]);
	}
	if(cl<tn){
		if(f[id-1][al][bl][cl+1])
		xsm=max(xsm,f[id-1][al][bl][cl+1]+c[id]);
		else xsm=max(xsm,dfs(id-1,al,bl,cl+1)+c[id]);
	}
	f[id][al][bl][cl]=xsm;
	return xsm;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		for(int i=1;i<=n;++i)
			for(int j=0;j<=tn;++j)
				for(int x=0;x<=tn;++x)
					for(int y=0;y<=tn;++y) f[i][j][x][y]=0;
		scanf("%d",&n);
		tn=n>>1;
		ans=0;
		for(int i=1;i<=n;++i) scanf("%d%d%d",&a[i],&b[i],&c[i]);
		printf("%d\n",dfs(n,0,0,0));
	}
	return 0;
}
