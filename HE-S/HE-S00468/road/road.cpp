/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 4 2 4
100 1 3 2 4
*/
#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL ans;
LL n,m,k,cnt,ff=0;
const LL N=1e4+5,K=15,M=5e6+5;
LL a[K][N],c[K],fa[M],f[M];
struct node{
	LL u,v,w;
}e[M];

bool cmp(node x,node y){
	return x.w<y.w;
}

LL mf(LL x){
	if(x==fa[x]) return x;
	return fa[x]=mf(fa[x]);
}

void hb(LL x,LL y){
	LL fx=mf(x);
	LL fy=mf(y);
	if(fx<fy) fa[fy]=fx;
	else fa[fx]=fy;
	return;
}

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=M;i++) fa[i]=i;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	cnt=m;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		int id=cnt+1;
		for(int j=1;j<=n;j++){
			cnt++;
			LL x;
			cin>>x;
			if(x) ff=1;
			e[cnt].u=id;
			e[cnt].v=j;
			e[cnt].w=x+c[i];	
		}
	}
	sort(e+1,e+1+cnt,cmp);
//	cout<<ff<<endl;
	if(!k){
		for(int i=1;i<=m;i++){
			int x=e[i].u,y=e[i].v,w=e[i].w;
			int fx=mf(x),fy=mf(y);
			if(fx!=fy){
				hb(fx,fy);
				ans+=w;
			}
		}
		cout<<ans;
		return 0;
	}
	else if(!ff){
		cout<<0;
		return 0;
	}
//	for(int i=1;i<=cnt;i++) cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;
	int num=0;
	for(int i=1;i<=cnt;i++){
//		cout<<i<<" "<<num<<" ***m"<<ans<<endl;
		if(num==n-1) break; 
		int x=e[i].u,y=e[i].v,w=e[i].w;
		int fx=mf(x),fy=mf(y);
		if(fx!=fy){
			num++;
			hb(fx,fy);
			ans+=w;
			if(x>m){
				if(!f[x]){
					n++;
					f[x]=1;
				}
				else ans-=c[x-m]; 
			}
			if(y>m){
				if(!f[y]){
					n++;
					f[y]=1;
				}
				else ans-=c[y-m];
			}
		}
	}
	cout<<ans;
	
	return 0;
}
