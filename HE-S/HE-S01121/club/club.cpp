#include<bits/stdc++.h>
using namespace std;
struct code{
	int a=0,b=0,c=0;
}qx[100];
int maxx=-1;
int n;
void dfs(int len,int ans,int x,int y,int z){
	if(len == n+1){
		maxx = max(maxx,ans);
		return;
	}
	else{
		if(x>=1){
			dfs(len+1,qx[len].a+ans,x-1,y,z);
		} 
		if(y>=1){
			dfs(len+1,qx[len].b+ans,x,y-1,z);
		}
		if(z>=1){
			dfs(len+1,qx[len].c+ans,x,y,z-1);
		}
	}
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>qx[i].a>>qx[i].b>>qx[i].c;
	}
	maxx=-1;
	dfs(1,0,n/2,n/2,n/2);
	printf("%d\n",maxx);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
}
