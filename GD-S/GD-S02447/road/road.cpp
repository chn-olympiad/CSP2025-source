#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e4+7,M=3e6+7; 
int n,m,k;
ll c[17][N],o[17];

struct e{
	int u,v; ll w;
} a[M];

bool aa(e x,e y){
	return x.w<y.w;
}

struct Misaka{
	int f[N];
	void init(int uu){
		for(int i=1;i<=uu;i++) f[i]=i;
	}
	int find(int x){
		return (x==f[x]?x:f[x]=find(f[x]));
	}
	bool merge(int x,int y){
		x=find(x),y=find(y);
		if(x==y) return false;
		f[x]=y; return true;
	}
};
Misaka Mikoto;

int main(){
	freopen("road.in" ,"r",stdin );
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%lld",&a[i].u,&a[i].v,&a[i].w);
	if(k==0){
		ll r=0;
		sort(a+1,a+m+1,aa);
		Mikoto.init(n);
		for(int i=1;i<=m;i++){
			if(Mikoto.merge(a[i].u,a[i].v)) r+=a[i].w;
		}
		printf("%lld",r);
		return 0;
	}
	
	bool vv=false;
	for(int i=1;i<=k;i++){
		scanf("%lld",&o[i]); if(o[i]) vv=true;
		bool hh=false;
		for(int j=1;j<=n;j++){
			scanf("%lld",&c[i][j]);
			if(c[i][j]==0) hh=true;
		}
		if(hh==false) vv=true;
	}
	
	if(vv==false){
		ll l=0;
		Mikoto.init(n+k);
		for(int j=1;j<=k;j++){
			for(int kk=1;kk<=n;kk++){
				a[++m]={n+j,kk,c[j][kk]};
			}
		}
		sort(a+1,a+m+1,aa);
		for(int kk=1;kk<=m;kk++){
			if(Mikoto.merge(a[kk].u,a[kk].v)) l+=a[kk].w;
		}
		printf("%lld",l);
		return 0;
	}
	
	
	return 0;
}

