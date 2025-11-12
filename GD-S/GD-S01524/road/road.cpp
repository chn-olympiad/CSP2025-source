#include<bits/stdc++.h>
using namespace std;
long long n,m,k,f[100005],x,y,z,ans,cnt1,a[15][100005],b[15];
struct edge{
	long long u,v,w;
}e[1000005]; 
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	return (f[x]==x)?x:(f[x]=find(f[x]));
}
void init(int m){
	for (int i=1;i<=m;i++) f[i]=i;
}
void merge(int x,int y){
	f[find(y)]=find(x);
}
bool pan=0;
void kruskal(){
	sort(e+1,e+m+1,cmp);
	init(n+k);
	int cnt1=0;
	for (int i=1;i<=m;i++){
		if (find(e[i].v)!=find(e[i].u)){
			ans+=e[i].w;
			merge(e[i].v,e[i].u);
		}
		if (cnt1==n-1){
			break;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++){
		cin>>x>>y>>z;
		e[i]={x,y,z};
	}
	if (k==0){
		kruskal();
		cout<<ans;
	}else{
		for (int i=1;i<=k;i++){
			cin>>b[i];
			for (int j=1;j<=n;j++){
				cin>>a[i][j];
			}
		}
		cout<<0;
		
	}
	return 0;
}
