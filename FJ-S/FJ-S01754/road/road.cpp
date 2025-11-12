#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
struct Edge{
	int u,v;
	long long w;
}a[M+N*10];
long long ans,c[15],cost[15][N];
int cnt,f[N],sum;
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
int find(int z){
	if(f[z]==z)return z;
	return f[z]=find(f[z]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int f,to,vi;
		cin>>f>>to>>vi;	
		a[++cnt].u=f;
		a[cnt].v=to;
		a[cnt].w=vi;
	}
	for(int i=1;i<=k;i++){
		bool f=0;
		cin>>c[i];
		if(c[i])f=1;
		for(int j=1;j<=n;j++){
			cin>>cost[i][j];
			if(cost[i][j])f=1;	
		}
		if(f==1){
			for(int j=1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					a[++cnt].u=j;
					a[cnt].v=k;
					a[cnt].w=c[i]+cost[i][j]+cost[i][k];
				}
			}
		}
		else{
			cout<<0;
			return 0;
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		int x=find(a[i].u),y=find(a[i].v);
		if(f[x]!=f[y]){
			ans+=a[i].w;
			//cout<<x<<' '<<y<<endl;
			sum++;
			f[x]=y;
			if(sum==n)break;
		}
	}
	cout<<ans;
	return 0;
} 
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4

