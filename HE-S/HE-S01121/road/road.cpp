#include<bits/stdc++.h>
using namespace std;
struct code{
	int u,k,w;
}qx[10000000];
int f[100100],n,m,kk,aa[100010];
bool cmp(code x,code y){
	return x.w<y.w;
}
int find(int x){
	if(x == f[x])return x;
	else return f[x] = find(f[x]);
}
void un(int x,int y){
	int tx = find(x),ty = find(y);
	if(tx != ty){
		f[tx] = find(f[ty]);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>kk;
	for(int i=1;i<=n;i++){
		f[i] = i;
	}
	for(int i=1;i<=m;i++){
		cin>>qx[i].u>>qx[i].k>>qx[i].w;
	}
	for(int i=1;i<=kk;i++){
		int xxx;
		cin>>xxx;
		for(int j=1;j<=n;j++){
			cin>>aa[j];
		}
		for(int j=1;j<=n;j++){
			for(int z=j+1;z<=n;z++){
				m+=1;
				qx[m].u = j;
				qx[m].k = z;
				qx[m].w = xxx+aa[z]+aa[j];
			}
		}
	}
	int m2 = m;
	sort(qx+1,qx+1+m,cmp);
	int ans=0;
	for(int i=1;i<=m2;i++){
		if(find(f[qx[i].u]) == find(f[qx[i].k])){
			cout<<ans;
			return 0;
		}
		un(qx[i].u,qx[i].k);
		ans += qx[i].w;
	}
}
