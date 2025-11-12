#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
const int INF=1e17;
struct node{
	int fr,to;
};
int n,m,k;
int x,y,z;
int a[N]; 
int zu[15][N];
int w[N][N];
int w1[N][N];
int ans=INF,ans1=INF;;
int nn;
int b[N];
node g[N];
int sumg;
//int h[N],sumh;
//int id=0,he[N],ne[N],c[N],to[N];
//void add(int x,int y,int z){
//	id++,c[id]=z,ne[x]=he[x],he[x]=id,to[id]=y;
//}
bool check(){
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]) return true; 
	}
	return false;
}
void dfs(int sum){
	ans=0;
	for(int i=1;i<=n;i++) a[i]=i;
	if(nn==n){
		b[1]=2;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(w[i][j]!=1e9+1){
					b[j]=b[i];
				}
			}
		}
		for(int i=1;i<=n;i++) if(b[i]!=2) return;
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=nlj++){
//			w1[i][j]=w[i][j];
//		} 
//	}
//	ans=w1[1][n];
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			for(int k=j+1;k<=n;k++){
//				if(w1[j][i]+w[i][k]<) w1[j][k]=w1[j][i]+w[i][k];
//			}
//		}
//	}
	int cnt=0,cnt1=INF;
	for(int i=1;i<=n;i++){
		if(a[i]!=i) continue;
		cnt=0,cnt1=1e9+1;
		for(int j=i+1;j<=n;j++){
			if(cnt1>w[i][j]){
				cnt=j,cnt1=w[i][j];
			}
		}
		if(cnt==0) return;
		ans+=cnt1;
		a[cnt]=a[i];
	}
	while(check()){
//		sumg=0;
		for(int i=1;i<=n;i++){
			if(a[i]=i){
//				sumg++;
				w[0][0]=1e9+1;
				for(int j=i+1;j<=n;j++){
					if(w[i][j]!=1e9+1&&a[i]!=a[j]&&w[i][j]<=w[g[sumg].fr][g[sum].to]){
						g[sumg].fr =i,g[sumg].to=j;
					}
				}
//				h[sumh]=i;
			}else{
				for(int j=1;j<=sumg;j++){
					if(a[g[j].to]==a[i]){
						break;
					}
				}
			}
//			for(int i=1;i<=n;i++)
		}
	}
	ans1=min(ans1,ans+sum);
}
void dfs1(int x,int k1){
	dfs1(x+1,k1);
	n++;
	for(int i=1;i<=n;i++){
		w[i][n]=zu[x][i];
		w[n][i]=zu[x][i];
	}
	dfs(zu[x][0]+k1);
	dfs1(x+1,k1+zu[x][0]);
	n--;
	dfs(k1);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>n>>m>>k;
	nn=n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) w[i][j]=1e9+1;
	}
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&x,&y,&z);
//		add(x,y,z),add(y,x,z);
		w[x][y]=z;
		w[y][x]=z;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++)scanf("%lld",zu[i][j]);
	}
	dfs1(1,0);
	cout<<ans1;
//	,add(i,j,zu[i][j])
	return 0;
}

