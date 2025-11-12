#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],sc;
//        下，右，上
int dx[4]={0,1,0};
int dy[4]={1,0,-1};
void dfs(int x,int y,int fang,int ci){
	if(a[ci]==sc){
		cout<<x<<' '<<y;
		return;
	}if(fang==1){
		if(x%2==0)fang=2;
		else fang=0;
	}else if(y==1 || y==n)fang=1;
	dfs(x+dx[fang],y+dy[fang],fang,ci+1);
} 
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sc=a[1];
	sort(a+1,a+1+n*m,cmp);
	dfs(1,1,1,1);
	return 0;
}