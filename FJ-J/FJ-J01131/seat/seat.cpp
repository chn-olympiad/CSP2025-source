#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],c,r,k,b[15][15];
	cin>>n>>m;
	memset(b,0,sizeof(b));
	for(int i=1;i<=n*m;i++) cin>>a[i];
	k=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				b[i][j]=a[i*n-n+j];
			}
		}else{
			for(int j=n;j>=1;j--){
				b[i][j]=a[i*n-j+1];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==k){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
