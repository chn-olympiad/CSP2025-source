#include<bits/stdc++.h>
using namespace std;
const int N=1e4+30;
const int M=1e6+2e5;
int fa[N],faa[N],kk[15];long long ans=0;
struct E{
	int to,from,v; 
};
E e[M];
int find(int x){
	return ((x^fa[x]) ? fa[x]=find(fa[x]) : x);
}
bool cmp(E a,E b){
	return a.v<b.v;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,x,y,z,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;faa[i]=1;
	}
	for(int i=n;i<=n+10;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		e[i].from=x;e[i].to=y;e[i].v=z;
	}
	if(k==0){
		sort(e+1,e+1+m,cmp);
		for(int i=1;i<=m;i++){
			x=e[i].from;
			y=e[i].to;
			if(find(x)!=find(y)){
				ans+=e[i].v;
				fa[find(x)]=fa[y];
			}
		}
		cout<<ans;
	}else{
		for(int i=1;i<=k;i++){
			cin>>kk[i];
			for(int j=1;j<=n;j++){
				cin>>z;
				m++;
				e[m].from=j;e[m].to=n+i;e[m].v=z;
			}
		}
		sort(e+1,e+1+m,cmp);
		for(int i=1;i<=m;i++){
			x=e[i].from;
			y=e[i].to;
			if(find(x)!=find(y)){
				ans+=e[i].v;
				fa[find(y)]=fa[x];
				if(y<=n){
					faa[fa[y]]+=faa[x];
					faa[x]=0;
					if(faa[y]>=n)break;
				}
			}
		}
		for(int i=1;i<=k;i++){
			if(fa[i+n]!=i+n)ans+=kk[i];
		}
		cout<<ans;
	}
	return 0;
}

