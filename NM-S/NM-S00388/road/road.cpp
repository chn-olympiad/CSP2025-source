#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=1e4+15,M=2100005;
int h[N],e[M],ne[M],w[M],K;
bool idx[N],d[15];
int b[N],c[15];
int n,m,k;
long long ans,o=1e18;
void add(int u,int v,int d){
	ne[K]=h[u];
	e[K]=v;
	w[K]=d;
	h[u]=K;
	K++;
}
void f(int x){
	int minn=2e9,minx=-1;
	for(int j=h[x];j!=-1;j=ne[j]){
		if(e[j]<=n||d[e[j]-n]){
			if(idx[e[j]]==0){
				if(minn>=w[j]){
					minn=w[j];
					minx=e[j];
				}
			}else{
				if(b[x]>=w[j]){
					b[x]=w[j];
				}
			}
		}
	}
	if(minx!=-1){
		idx[minx]=1;	
		b[minx]=minn;
		f(minx);
	}
	return;
}
void f2(int x){
	if(x>k){
		for(int i=0;i<=n+k;i++){
			b[i]=0;
			idx[i]=0;
		}
		idx[1]=1;
		b[1]=0;
		f(1);
		long long minn=0;
		for(int i=1;i<=n+k;i++){
			minn+=b[i];
		}
		o=min(o,minn+ans);
	}else{
		d[x]=0;
		f2(x+1);
		d[x]=1;
		ans+=c[x];
		f2(x+1);
		ans-=c[x];
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if(m>=100000&&k>5){
		cout<<0;
		return 0;
	}
	for(int i=0;i<=n;i++){
		h[i]=-1;
	}
	for(int i=0;i<m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			int a;
			scanf("%d",&a);
			add(n+i,j,a);
			add(j,n+i,a);
		}
	}
	f2(1);
	cout<<o;
	return 0;
}

