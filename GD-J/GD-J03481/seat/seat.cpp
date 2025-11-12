#include <bits/stdc++.h>
using namespace std;
int a[101];
int dp[11][11];
int n,m,k,ip=0;
bool f=true;
void dfs(int x,int y){
	if(ip==n*m){
		return;
	}
	else if((x%n==1&&x!=1)||x==0){
		if(f==true){
			f=false;
			dfs(x-1,y+1);
		}
		else{
			f=true;
			dfs(x+1,y+1);
		}
	}else if(f==true){
		ip++;
		dp[x][y]=a[ip];
		dfs(x+1,y);
		
	}else if(f==false){
		ip++;
		dp[x][y]=a[ip];
		dfs(x-1,y);
		
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+(n*m)+1,greater<int>());
	dfs(1,1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(dp[i][j]==k) cout<<j<<" "<<i;
		}
	}
	return 0;
	
} 
