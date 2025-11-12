#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+5;
int n,a[N][5],ans;
struct node{
	int t,id;
	inline bool operator < (const node& s1)const{
		return s1.t<t;
	}
};
void dfs(int x,int u,int v,int w,int y){
	if(x==n+1){
		ans=max(ans,y);
		return ;
	}
	if(u+1<=n/2){
		dfs(x+1,u+1,v,w,y+a[x][1]); 
	}
	if(v+1<=n/2){
		dfs(x+1,u,v+1,w,y+a[x][2]);
	}
	if(w+1<=n/2){
		dfs(x+1,u,v,w+1,y+a[x][3]);
	}
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	ans=0;
	dfs(1,0,0,0,0);
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int t;cin>>t;
	while(t--)	solve();
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
