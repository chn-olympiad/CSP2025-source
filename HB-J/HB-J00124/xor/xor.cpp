#include<bits/stdc++.h>
using namespace std;
int a[500100],Xr[500100];
int lrXr[1500][1500];
int m,n;
long long T=0;
int lrX(int l,int r){
	return Xr[l-1]^Xr[r];
}
void dfs(int p,int q,int x,int y,long long ans){
	for(int i=y+1;i<=p;i++){
		for(int j=i;j<=p;j++){
			if(lrXr[i][j]==q){
				dfs(p,q,i,j,ans+1);
				//dfs(p,q,x,y,ans);
			}
		}
	}T=max(T,ans);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>m>>n;
	for(int i=1;i<=m;i++) cin>>a[i];
	Xr[1]=a[1];
	for(int i=2;i<=m;i++) Xr[i]=Xr[i-1]^a[i];
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j++){
			lrXr[i][j]=lrX(i,j);
			//cout<<lrXr[i][j]<<' ';
		}//cout<<'\n';
	}
	//cout<<lrXr[4][4]<<'\n'<<'\n';
	dfs(m,n,0,0,0);
	cout<<T;
	return 0;
}

