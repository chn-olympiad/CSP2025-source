#include<bits/stdc++.h>
using namespace std;
//#define int long long
int a[101][101];
int f[10001];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>f[i];
	}
	int g=f[1],t=0;
	sort(f+1,f+n*m+1,cmp);
	for(int j=1;j<=m;j++){
		if(j%2==0){
			for(int i=n;i>=1;i--){
				a[i][j]=f[++t];
			} 
		}else{
			for(int i=1;i<=n;i++){
				a[i][j]=f[++t];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==g){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}