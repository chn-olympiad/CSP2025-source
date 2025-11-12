#include<bits/stdc++.h>
using namespace std;
int n,m;
int seat[15][15];
struct cs{
	int cj,pm;
	int h,l;
};
bool cmp(cs x,cs y){
	return x.cj>y.cj;
}
void dfs(int x,int y,int k){
	if(x==n&&y==m+1){
		return;
	}
	seat[x][y]=k;
	if(x-1!=0&&seat[x-1][y]==0){
		dfs(x-1,y,k+1);
	}else if(x+1!=n+1&&seat[x+1][y]==0){
		dfs(x+1,y,k+1);
	}else{
		dfs(x,y+1,k+1);
	}
	return;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cs a[n*m+1];
	int sum=0;
	for(int i=1;i<=n*m;i++){
		sum++;
		cin>>a[sum].cj;
	}
	int xr=a[1].cj;
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		a[i].pm=i;
	}
	dfs(1,1,1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[seat[i][j]].cj==xr){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
