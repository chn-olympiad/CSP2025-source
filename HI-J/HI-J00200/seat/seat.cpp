#include<bits\stdc++.h>
using namespace std;
const int N=15;
int n,m,r,a[N*N],mp[N][N],dx[]={1,-1},dy[]={0,0};
bool cmp(int x,int y){
	return x>y;
}
void dfs(int x,int y,int cnt,int d){
	if(cnt==n*m) return ;
	int now_x=x+dx[d],now_y=y+dy[d];
	if(now_x>n||now_x<1||now_y>m||now_y<1){
		d=1-d;
		now_y=y+1,now_x=x;
	}
	mp[now_x][now_y]=cnt+1;
	dfs(now_x,now_y,cnt+1,d);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	dfs(0,1,0,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[mp[i][j]]==r){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}

