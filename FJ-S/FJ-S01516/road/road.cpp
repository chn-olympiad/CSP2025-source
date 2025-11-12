#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct edge{
	int u;int v;int w;
}e[1000100];
long long suu[1010][1010];
int f[100100];
int find(int x){
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
bool ise[1000100];
int c[1001];
long long r[101][100100];
bool cmp(edge i1,edge i2){
	return i1.w<i2.w;
}
int cnt;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(suu,-1,sizeof(suu));
	for(int i=1;i<=n;i++) f[i]=i;
	if(k!=0){
		for(int i=1;i<=m;i++){
			int U,V,W;
			scanf("%d",&U);scanf("%d",&V);scanf("%d",&W);
			if(U>V) swap(U,V);
			suu[U][V]=W;
		}
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++) cin>>r[i][j]; 
			for(int j=1;j<=n;j++){
				for(int k=1;k<j;k++){
					if(suu[k][j]>=0)	suu[k][j]=min(suu[k][j],r[i][j]+r[i][k]);
					else suu[k][j]=r[i][j]+r[i][k];
				}
			}
		}
		cnt=0;
		for(int j=1;j<=n;j++){
			for(int k=1;k<j;k++){
				e[++cnt].u=j;
				e[cnt].v=k;
				e[cnt].w=suu[k][j];
			//	cout<<suu[k][j]<<' ';
			}//cout<<endl;
		}
	}else{
		for(int i=1;i<=m;i++){
			scanf("%d",&e[i].u);scanf("%d",&e[i].v);scanf("%d",&e[i].w);
		}
		cnt=m;
	}
	sort(e+1,e+1+cnt,cmp);
	long long ans=0;
	int sf=0;
	for(int i=1;i<=cnt;i++){
		if(find(e[i].u)!=find(e[i].v)){
			ans+=e[i].w;
			f[find(e[i].u)]=f[find(e[i].v)];
		sf++;
		}
		
	}

	/*
	4 4 1
	 1 4 6
	2 3 7
	4 2 5
	4 3 4
	0 1 8 2 4*/
	cout<<ans;	
	fclose(stdin);
	fclose(stdout);
}
