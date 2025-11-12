#include<bits/stdc++.h>
using namespace std;
const int N=3e6+10;
int ans[20][20],xl[500];
int n,m;
bool cmp(int x,int y){
	return x>y;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>xl[i];
	}
	int xa=xl[1];
	sort(xl+1,xl+n*m+1,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		ans[x][y]=xl[i];
		if(x==1){
			if(y%2==1){
				x++;
			}else{
				y++;
			}
			continue;
		}else if(x==n){
			if(y%2==1){
				y++;
			}else{
				x--;
			}
			continue;
		}else{
			if(y%2==1){
				x++;
			}else{
				x--;
			}
			continue;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans[i][j]==xa){
				cout<<j<<' '<<i;
			}
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
}
