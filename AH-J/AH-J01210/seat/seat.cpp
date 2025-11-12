#include <bits/stdc++.h>
using namespace std;
int a[1005],g[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	int cnt=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				g[j][i]=a[cnt++];
			}
		}
		else{
			for(int j=n;j>=1;j--){
				g[j][i]=a[cnt++];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(g[i][j]==r){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
