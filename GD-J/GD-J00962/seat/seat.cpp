#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,a[10010];
int e[105][105];
int R;
bool cmp(int xx,int yy){
	return xx>yy;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int j=1;j<=m;j+=2){
		for(int i=1;i<=n;i++){
			e[i][j]=a[i+(j-1)*n];
		}
	}
	for(int j=2;j<=m;j+=2){
		for(int i=n;i>=1;i--){
			e[i][j]=a[j*n-i+1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(e[i][j]==R) cout<<j<<" "<<i;
		}
	}
	return 0;
}
