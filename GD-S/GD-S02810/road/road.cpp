 
#include<bits/stdc++.h>
using namespace std;
const int N=1e4+50,M=1e6+50;
int n,m,k;
struct ttl{
	int from,to,vl;
};
struct edge{
	int to,vl;
};
vector<edge>e[N];
ttl a[M];
int f[N],ans=0,cst[11],bd[11][N];
bool cmp(ttl x, ttl y){
	return x.vl<y.vl;
}
int rfind(int x){
	if(f[x]==x)return x;
	else return f[x]=rfind(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,val;
		cin>>u>>v>>val;
		a[i]={u,v,val};
	}
	for(int i=1;i<=k;i++){
		cin>>cst[i];
		for(int j=1;j<=n;j++){
			cin>>bd[i][j];
		}
	}
	sort(a+1,a+m+1,cmp);
	int nn=n,i=1;
	while(nn>1){
		if(i>m)break;
		int r1=rfind(a[i].from);
		int r2=rfind(a[i].to);
		if(r1!=r2){
			f[r1]=r2;
			ans+=a[i].vl;
			nn--;
		}
		i++;
	}
	cout<<ans;
} 
