#include<bits/stdc++.h>
#define M 2000100
#define N 20100
#define K 20
#define int long long
using namespace std;
struct li{
	int u,v,va;
};
li e[M];
int n,m,nds,k,f[N],cnt,go[K][N],us[K];

bool cmp(li x,li y){
	return x.va<y.va;
}

int find(int x){
	return (f[x]==x?x:f[x]=find(f[x]));
}

int kruskal(){
	int sum=0;
	for(int i=1;i<=nds;i++){
		f[i]=i;
	}
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu!=fv){
			f[fu]=fv;
			sum+=e[i].va;
		}
	}
	return sum;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].va;
	}
	cnt=m;
	for(int i=1;i<=k;i++){
		cin>>us[i];
//		e[++cnt]=li{n+k+1,n+i,us[i]};
		for(int j=1;j<=n;j++){
			cin>>go[i][j];
			e[++cnt]=li{n+i,j,go[i][j]};
		}
	}
	nds=n+k+(k>0);
	cout<<kruskal();
	return 0;
//	cin>>n>>m>>k;
//	for(int i=1;i<=m;i++){
//		cin>>e[i].u>>e[i].v>>e[i].va; 
//	}
//	for(int i=1;i<=k;i++){
//		cin>>us[i];
//		for(int j=1;j<=n;j++){
//			cin>>go[i][j];
//		}
//	}
//	cnt=m;nds=n;
//	int ans=kruskal();
//	for(int s=1;s<(1<<k);s++){
//		cnt=m;nds=n;
//		int sum=0;
//		for(int i=0;i<k;i++){
//			if(s&(1<<i)){
//				sum+=us[i+1];nds++;
//				for(int j=1;j<=n;j++)
//					e[++cnt]=li{nds,j,go[i+1][j]};
//			}
//		}
//		ans=min(ans,sum+kruskal());
//	}
//	cout<<ans;
	return 0;
}
/*
 4 4 2
 1 4 6
 2 3 7
 4 2 5
 4 3 4
 1 1 8 2 4
 100 1 3 2 4
*/
