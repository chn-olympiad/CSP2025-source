#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[15][15],b[1000],er,wei;
int dir[3][3]={{0,1},{-1,0},{1,0}};
bool vis[15][15];
bool in(int a,int b){
	return 1<=a&&a<=n&&1<=b&&b<=m;
}
int dfs(int x,int y,int k){
	for(int i=0;i<4;i++){
		int dx=dir[i][0];
		int dy=dir[i][1];
		if(in(dx,dy)&&vis[dx][dy]==0){
			vis[dx][dy]=1;
			k++;
			if(k==wei){
				return dx,dy;
			}
			else{
				dfs(dx,dy,k);
			}
	}
	}
	
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++){
			cin>>b[i];
			er=b[1];	
	}
	sort(b+1,b+k+1);
	for(int i=1;i<=k;i++){
		if(b[i]==er){
			wei=i-1;
		}
	}
	if(n==1&&m==1){
		cout<<1<<" "<<1;
		return 0;
	}
	if(n==2){
		cout<<1<<" "<<wei;
	}
	else{
		cout<<dfs(dx,dy,k);
	}	
}
