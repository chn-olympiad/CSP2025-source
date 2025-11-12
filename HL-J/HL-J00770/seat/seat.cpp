#include<bits/stdc++.h>
using namespace std;
int a[15][15],b[110],n,m,e,dir[3][2]={{1,0},{-1,0},{0,1}},c,r;
bool vis[15][15];
void f(int x,int y,int idx){
	if(b[idx]==e){
		c=y;
		r=x;
		return;
	}
	for(int i=0;i<3;i++){
		int dx=x+dir[i][0];
		int dy=y+dir[i][1];
		if(dx>=1 && dx<=n && dy>=1 && dy<=m && vis[dx][dy]==0){
			vis[dx][dy]=1;
			f(dx,dy,idx+1);
			return;
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> b[i];
		if(i==1){
			e=b[i];
		}
	}
	sort(b+1,b+1+n*m,greater<int>());
	vis[1][1]=1;
	a[1][1]=b[1];
	f(1,1,1);
	cout << c << ' ' << r;
    return 0;
}
