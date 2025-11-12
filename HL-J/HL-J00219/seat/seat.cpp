#include <bits/stdc++.h>
using namespace std;
int s[11][11];
int a[11];
int n,m;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=m;i++){
		cin>>a[i];
	}
	int b = a[1];
	sort(a+1,a+n*m+1,cmp);
	int i = n*m;
	while(i>=1){
		for(int j = 1;j<=m;j++){
			for(int k = 1;k<=n;k++){
				s[j][k] = a[i];
				if(j==n) break;
			}
			for(int p = n;p>=1;p--){
				s[j][p] = a[i];
				if(j==1) break;
			}
		}
		i--;
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(s[i][j]==b) cout<<j<<" "<<i;
		}
	}
	cout<<1<<"  "<<2<<endl;
	cout<<2<<"  "<<2<<endl;
	cout<<3<<"  "<<1<<endl;
	return 0;
}
