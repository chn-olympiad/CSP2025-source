#include<bits/stdc++.h>
using namespace std;
int a[101];
bool b[11][11];
bool cmp(int x,int y){
	return x>y? 1:0;
}
int n,m;
int i = 1;
int fx[5] = {0,0,0,1,0};
int fy[5] = {0,1,-1,0,0};
void dfs(int x,int y,int cnt){
	b[x][y] = 1;
	if(cnt==i){
		cout<<x<<' '<<y;
		exit(0);
	}
	for(int i = 1;i<=4;i++){
		int dx = fx[i]+x;
		int dy = fy[i]+y;
		if(b[dx][dy]!=1&&dx>=1&&dx<=n&&dy>=1&&dy<=m){
			dfs(dx,dy,cnt+1);	
		} 
	} 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int j = 1;j<=n*m;j++){
		cin>>a[j];
	}
	int score = a[1];
	sort(a+1,a+n*m+1,cmp);
	
	while(a[i]!=score){
		i++;
	}
	b[1][1] = 1;
	dfs(1,1,1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
