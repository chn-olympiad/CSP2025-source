#include<bits/stdc++.h>
using namespace std;
int n,m,a[25][25],st[1145];
bool cmp(int x,int y) {
		return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) cin>>st[i];
	int stt=st[1];
	sort(st+1,st+(n*m),cmp);
	int ij=1,x=1,y=1;
	while(ij<=n*m){
		while(x<=n) {
			a[x][y]=st[ij];
			ij++;
			x++;
		}
		y++,ij--;
		while(x>=1) {
			a[x][y]=st[ij];
			ij++;
			x--;
		}
		y++,ij--;
	}
	/*for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(a[i][j]==stt) {
					cout<<j<<" "<<i;
					return 0;
			}
		}
	}
	return 0;
}
