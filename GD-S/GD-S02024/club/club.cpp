#include <bits/stdc++.h>
using namespace std;
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0


1
4
0 1 0
0 1 0
0 2 0
0 2 0

*/
#define int long long
const int N=1e5+10;
int n;
int t;
struct member{
	int a,b,c;
}m[N];
bool vis[N];
int maxx=INT_MIN;
int suma,sumb,sumc;
void dfs(int x,int a,int b,int c,int ex){
	vis[x]=true;
	if(ex==1){
		maxx=max(maxx,(suma+sumb+sumc));
	}
	for(int i=x+1;i<=n;i++){
		if(a<n/2){
			suma+=m[i].a;
			--ex;
			dfs(i,a+1,b,c,ex);
			ex++;
			suma-=m[i].a;
		}
		if(b<n/2){
			sumb+=m[i].b;
			--ex;
			dfs(i,a,b+1,c,ex);
			ex++;
			sumb-=m[i].b;
		}
		if(c<n/2){
			sumc+=m[i].c;
			--ex;
			dfs(i,a,b,c+1,ex);
			ex++;
			sumc-=m[i].c;
		}
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>m[i].a>>m[i].b>>m[i].c;
		}
		for(int i=1;i<=n;i++){
			suma=m[i].a;
			dfs(i,1,0,0,n);
			suma=sumb=sumc=0;
			sumb=m[i].b;
			dfs(i,0,1,0,n);
			suma=sumb=sumc=0;
			suma=m[i].c;
			dfs(i,0,0,1,n);
			suma=sumb=sumc=0;
			memset(vis,0,sizeof(vis));
		}
		cout<<maxx<<'\n';
		maxx=INT_MIN;
	}
	
	return 0;
}
