//GZ-S00347 贵阳市华师一学校 田淑文
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5;
ll n,m,k,fa[N],ans,v[15],w[15],f[15][N],minh,id; 
struct note{
	int u,v,val;
}a[11*N];
//跑最小生成树 
int cmp(note x,note y){
	return x.val<y.val;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
	   cin>>a[i].u>>a[i].v>>a[i].val;
	}
	for(int i=1;i<=k;i++){
		cin>>w[i+m];
		for(int j=1;j<=n;j++){
			cin>>f[i+m][j];
			f[j][i+m]=f[i+m][j];
		}
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		int t1=find(a[i].u),t2=find(a[i].v);
		if(t1==t2) continue;
		fa[t1]=t2;
		minh=1e9,id=0;
		for(int j=1;j<=k;j++){
			if(v[j+m]&&minh<f[a[i].u][j+m]+f[j+m][a[i].v]){
					minh=f[a[i].u][j+m]+f[j+m][a[i].v];
			}else{
				if(f[a[i].u][j+m]+f[j+m][a[i].v]+w[j+m]<=minh){
					minh=f[a[i].u][j+m]+f[j+m][a[i].v]+w[j+m];
					id=j+m;
				}
			}
		}
		if(minh<=a[i].val){
			v[id]=1;
			ans+=minh;
		}else ans+=a[i].val;
	}
	cout<<ans<<endl;
	return 0;
} 
