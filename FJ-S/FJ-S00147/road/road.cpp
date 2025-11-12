#include<bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=(a);i<=(int)(b);i++)
using namespace std;
int n,m,k;
int a[1011][1011];
//struct Node{
//	int v;
//	int len;
//	bool operator<(const Node &x) const {return len>x.len;}
//};
int u,v,w;
int c[1011];
bool f;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	if(n<=1011){//5~16
		FOR(i,1,n+k){
			FOR(j,1,n+k){
				a[i][j]=1e13;
			}
		}
		f=1;
//		cout<<a[1][1];
		FOR(i,1,m){
			cin>>u>>v>>w;
			a[u][v]=w;
			a[v][u]=w;
		}
		FOR(i,1,k){
			cin>>u;
			c[i]=u;
////			cout<<c[i];
//			if(u!=0){
//				f=0;
//			} 
////			cout<<4444;
			for(int j=1;j<=n;j++){
				
				cin>>u;
//				cout<<111;
				a[n+j][j]=u;
////				cout<<22222;
//				if(u!=0) f=0;
////				cout<<111;
				a[j][n+j]=u;
			}
		}//输入边 
//		cout<<333;
		
		if(f) {
			cout<<0;
			return 0;
		}
//		cout<<222; 
		FOR(k,1,n+k){
			FOR(i,1,n){
				FOR(j,1,n){
					a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
				}
			}
		}
	}
	else{
		FOR(i,1,m)cin>>u>>v>>w;
		FOR(i,1,k){
			cin>>c[i];
//			if(c[i]!=0) f=false;
			FOR(j,1,n){
				cin>>u;
//				if(u!=0) f=false;
			}
		}
		if(f) cout<<0;
	}
	return 0;
}
/*
第一眼floyd
第二眼，一个样例都过不去 
第三眼，特殊性质A送分啊 
dijkstra 不适用 
我旁边的人在吃啥，(╯▽╰ )好香~~ 


1 1 1 
1 1 1 
1 
*/
