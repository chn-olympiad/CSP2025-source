#include<bits/stdc++.h>
using namespace std;
int n,m,a[10001];
int b[101][101];
bool cmp(int x,int y) {
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>n>>m;
	for(int i=1; i<=n*m; i++)cin>>a[i];
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1,cnt=0;
	while(x<=n&&y<=m) {
		b[x][y]=a[++cnt];
		if(y%2==1){
			if(x==n)y++;
			else x++;
		} else {
			if(x==1)y++;
			else x--;
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(b[i][j]==r) {
				cout<<j<<" "<<i<<"\n";
				return 0;
			}
		}
	}
	return 0;
}
