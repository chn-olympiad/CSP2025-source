#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int T,n,a[N][4],g[4],bn,aa[N];
bool vis[N];
//ll f[35][35][35][35];
struct node{
	int x,to,id;	
}b[3*N];
ll ans; 
bool cmpb(node u,node v){
	return u.x>v.x;
}
bool cmpA(int x,int y){
	return x>y;
}
void dfs(int x,ll val){//µÚx¸öÈË 
	if(x==n+1){
		ans=max(ans,val);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(g[i]>=n/2)continue;
		g[i]++;
		dfs(x+1,val+a[x][i]);
		g[i]--;
	}
}
void solve(){
	memset(g,0,sizeof(g));
	ans=0;
	dfs(1,0);
	cout<<ans<<'\n';
}
//void dp(){
//	for(int i=0;i<n;i++){
//		for(int x=0;x<n/2;x++){
//			for(int y=0;y<n/2;y++){
//				for(int z=0;z<n/2;z++){
//					if(x+y+z!=i)continue;
//				    f[i+1][x+1][y][z]=f[i][x][y][z]+a[i+1][1];
//				    f[i+1][x][y+1][z]=f[i][x][y][z]+a[i+1][2];
//				    f[i+1][x][y][z+1]=f[i][x][y][z]+a[i+1][3];
//				}
//			}
//		}
//	}
//	ll ans=0;
//	for(int x=0;x<=n/2;x++){
//		for(int y=0;y<=n/2;y++){
//			for(int z=0;z<=n/2;z++){
//				if(x+y+z!=n)continue;
//				ans=max(ans,f[n][x][y][z]);
//			}
//		}
//	}
//	cout<<ans<<'\n';
//}
void A(){
	for(int i=1;i<=n;i++){
		aa[i]=a[i][1];
	}
	sort(aa+1,aa+1+n,cmpA);
	ans=0;
	for(int i=1;i<=n/2;i++){
	    ans+=aa[i];
	}
	cout<<ans<<'\n';
} 
void dfs1(int x,int step,ll val){
	if(step==n){
		ans=max(ans,val);
		return ;
	}
	if(x==bn+1)return ;
//	if(bn-x+1)
	if(bn-x+1<n-step)return ;
	if((n-step)*b[x-1].x+val<ans)return ;
	for(int i=x;i<=bn;i++){
		int v=b[i].x,to=b[i].to,id=b[i].id;
		if(g[to]>=n/2||vis[id])continue;
		g[to]++;
		vis[id]=1;
		dfs1(i+1,step+1,val+v);
		g[to]--;
		vis[id]=0;
	} 
}
void solve2(){
	bn=0;
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			b[++bn].x=a[i][j];
			b[bn].to=j;
			b[bn].id=i;
		}
	}
	memset(g,0,sizeof(g));
	sort(b+1,b+1+bn,cmpb);
//	for(int i=1;i<=bn;i++){
//		cout<<b[i].x<<' '<<b[i].to<<'\n';
//	}
	memset(vis,0,sizeof(vis));
	dfs1(1,0,0); 
	cout<<ans<<'\n';
}
//void solve2(){
	
//}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		bool fa=1,fb=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(j==2||j==3){
					if(a[i][j])fa=0;
				}
				if(j==3){
					if(a[i][j])fb=0;
				}
			}
		}
		if(n<=10){
			solve();
			continue;
		}
////		dp();
		if(fa)A(); 
//		if(fb)B();
		solve2();
	}
	return 0;
} 
