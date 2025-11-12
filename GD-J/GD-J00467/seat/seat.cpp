#include<bits/stdc++.h>
using namespace std;
int a[50][50],t[1500];
int n,m,r;
void dfs(int x,int y,int f,int k){
	a[x][y]=t[k];
	if(f==1){
		if(x<n) dfs(x+1,y,f,k+1);
		else if(y<n) dfs(x,y+1,!f,k+1);
	}
	if(f==0){
		if(x>1) dfs(x-1,y,f,k+1);
		else if(y<n) dfs(x,y+1,!f,k+1);
	}
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	//cin>>r;
	for(int i=1;i<=n*m;i++){
		cin>>t[i];
	}
	r=t[1];
	sort(t+1,t+1+n*m,cmp);
	dfs(1,1,1,1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==r){
				cout<<j<<" "<<i<<"\n";
				return 0;
			}
		}
	}
	return 0;
} 
