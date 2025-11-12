#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 10005
#define M 1000005
int n,m,k;
int cur;
int flag[N][N];
int u[M],v[M],w[M];
struct NODE{
	int u,v,w;
};
NODE f[M];
int c[15];
int a[15][N];
int fa[N];
bool cmp(NODE x,NODE y){
	return x.w<y.w;
}
void init(int nk){for(int i=1;i<=nk;i++) fa[i]=i;}
int find(int x){return (fa[x]==x)? x : find(fa[x]);}
void change(int x,int y){fa[find(y)]=fa[x];}
int f1(){
	sort(f+1,f+cur+1,cmp);
	int sum=0;
	int num=n; 
	//cout<<num<<"\n";
	for(int i=1;i<=cur;i++){
		//cout<<f[i].u<<" "<<f[i].v<<" "<<f[i].w<<"\n\n";
		if(find(f[i].u)==find(f[i].v)) continue;
		sum+=f[i].w;
		num--;
		change(f[i].u,f[i].v);
		if(num==1) return sum;
	}
	return -1;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	init(n);
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>w[i];
		flag[u[i]][v[i]]=flag[v[i]][u[i]]=w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
//	for(int i=1;i<=k;i++){
//		for(int j=1;j<=n;j++){
//			cout<<a[i][j]<<"a ";
//		}
//		cout<<"\n\n";
//	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int d=j+1;d<=n;d++){
				if(flag[j][d]!=0) flag[j][d]=flag[j][d]=min(flag[j][d],c[i]+a[i][j]+a[i][d]);
				else flag[j][d]=flag[d][j]=c[i]+a[i][j]+a[i][d];
				//cout<<i<<" "<<j<<" "<<d<<" "<<c[i]<<" "<<a[i][j]<<" "<<a[i][d]<<"\n";
			}
		}
	}
	//cout<<"\n";
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			f[++cur]={i,j,flag[i][j]};
			//cout<<f[cur].u<<" "<<f[cur].v<<" "<<f[cur].w<<"\n\n";
		}
	}
	int ans=f1();
	cout<<ans<<"\n";
	fclose(stdout);
	fclose(stdin);
	return 0;
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4



