#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long cww[10004][10004],llk[10004][10004];
long long sum=0;
struct cs{
	long long u,v,w;	
}cw[10004];
struct xc{
	long long xg,xw[10004];
	bool mai=false;
}x[15];
int f[10004];

bool cmp(cs k,cs l){
	return k.w<l.w;
}

int fd(int kl){
	if(f[kl] == kl)return kl;
	else return f[kl]=fd(f[kl]);
}

bool findf(int x,int y){
	int xf=fd(x),yf=fd(y);
	if(xf == yf){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=n;i++){
		f[i]=i;
	}
	
	
	 
	for(long long i=1;i<=m;i++){
		cin>>cw[i].u>>cw[i].v>>cw[i].w;
		cww[cw[i].u][cw[i].v]=cw[i].w;
		cww[cw[i].v][cw[i].u]=cw[i].w;
	}
	for(long long i=1;i<=k;i++){
		cin>>x[i].xg;
		for(long long j=1;j<=n;j++){
			cin>>x[i].xw[j];
			for(long long kk=1;kk<j;kk++){
				if(x[i].xw[kk]+x[i].xw[j]+x[i].xg <= cww[kk][j]){
					llk[kk][j]=i;
					llk[j][kk]=i;
				}
				cww[kk][j]=min(cww[kk][j] , x[i].xw[kk]+x[i].xw[j]+x[i].xg);
				cww[j][kk]=min(cww[j][kk] , x[i].xw[kk]+x[i].xw[j]+x[i].xg);
				
			}
		}
		
	}
	sort(cw+1,cw+m+1,cmp);
	
	
	for(long long i=1;i<=n;i++){
		long long mi=cw[i].u,mj=cw[i].v;
		if( !findf(mi , mj) ){
			f[mi]=f[mj];
			if(cww[mi][mj] < cw[i].w && !x[llk[mi][mj]].mai){
				sum+=cww[mi][mj];
				x[llk[mi][mj]].mai=true;
			}
			else if(cww[mi][mj] < cw[i].w && x[llk[mi][mj]].mai){
				
			}
			else sum+=cw[i].w;
		}
	}
	cout<<sum;
	return 0;
}
