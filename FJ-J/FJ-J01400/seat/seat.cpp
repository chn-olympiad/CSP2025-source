#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[10005];
int b[105][105];
bool cmp(int x,int y){
	return x>y;
}
int fx,fy,cnt;
void dfs(int fx,int fy,int cnt){
	b[fx][fy]=a[cnt];
	if(fy%2==1){
		cnt++;
		if(fx==n){
			if(fy==m) return;
			fy++;
		}
		else fx++;
	}
	else{
		cnt++;
		if(fx==1){
			if(fy==m) return;
			fy++;
		}
		else fx--;		
	}
	dfs(fx,fy,cnt);
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	sort(a+1,a+n*m+1,cmp);
	dfs(1,1,1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==k){
				cout<<j<<" "<<i;
				exit(0);
			}
		}
	}
	return 0;
}
