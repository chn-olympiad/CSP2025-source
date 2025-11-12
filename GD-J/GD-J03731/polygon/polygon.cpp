#include<bits/stdc++.h>
using namespace std;
int n,a[10005],t;
int ans,kkk;
set<int> s; 
void dfs(int u,int x,int y,int k,int p){
	if(!u) dfs(u+1,x,y,k,p);
	if(u>n+1) return ;
	if(x>y*2&&k>=3) s.insert(p);
	dfs(u+1,x,y,k,p);
	dfs(u+1,x+a[u],max(y,a[u]),k+1,p|(1<<u));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(0,0,0,0,0);
	cout<<((s.size()/2)%998244353);
	return 0;
}
