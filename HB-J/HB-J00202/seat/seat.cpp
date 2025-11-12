#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105],wz[105],ww[11][11];
bool f[105]={0};
bool cmp(int a,int b){
	return a>b;
}
void solve(){
	cin>>n>>m;
	int x=n*m;
	for(int i=1;i<=x;i++){
		cin>>a[i];
		wz[i]=a[i];
	}
	sort(a+1,a+x+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			ww[i][j]=a[i*j];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(ww[i][j]==wz[1]){
				cout<<i<<" "<<j;
			}
		}
	}
	return;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
