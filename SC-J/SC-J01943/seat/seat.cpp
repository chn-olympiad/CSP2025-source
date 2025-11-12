#include<bits/stdc++.h>
using namespace std;
const int N=15;
int a[N][N],b[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int ans=b[1];
	sort(b+1,b+1+n*m,cmp);
	int cnt=1;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				a[i][j]=b[cnt++];
			}
		}else{
			for(int i=n;i>=1;i--){
				a[i][j]=b[cnt++];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==ans){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}