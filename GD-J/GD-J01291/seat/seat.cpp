#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
void solve();
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
void solve(){
	int a[15][15];
	int n,m;
	int b[105];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int k=b[1],ans=0;
	sort(b+1,b+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				ans++;
				a[j][i]=b[ans];
			}
		}
		else{
			for(int j=n;j>=1;j--){
				ans++;
				a[j][i]=b[ans];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==k){
				cout<<j<<' '<<i;
				return ;
			}
		}
	}
	return ;
}
