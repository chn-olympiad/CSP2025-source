#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int n,m,p,x;
int g[N*N],a[N][N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>g[i];
	}
	x=g[1];
	sort(g+1,g+1+n*m);
	reverse(g+1,g+1+n*m);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				a[i][j]=g[++p];
			}
		}else{
			for(int i=n;i>=1;i--){
				a[i][j]=g[++p];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==x){
				cout<<j<<" "<<i<<endl;
				return 0;
			}
		}
	}
	return 0;
}
