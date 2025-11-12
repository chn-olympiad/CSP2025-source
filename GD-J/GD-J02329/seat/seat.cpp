#include<bits/stdc++.h> 
#define int long long
using namespace std;
int n,m,b[15][15],x=1,y=1;
struct nd{
	int v,id;
}a[105];
bool cmp(nd x,nd y){
	return x.v>y.v;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i].v;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++){
		b[x][y]=a[i].id;
		if (y%2){
			x++;
			if (x>n){
				x=n,y++;
			}
		}else{
			x--;
			if (x<1){
				x=1,y++;
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (b[i][j]==1){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
}
