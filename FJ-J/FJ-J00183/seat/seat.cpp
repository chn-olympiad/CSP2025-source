#include<bits/stdc++.h>
using namespace std;
const int N=110;
long long n,m,d[N],se[N][N],sk,p=0;
int cmp(int a,int b){
	 return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int y=n*m;
	for(int i=1;i<=y;i++) cin>>d[i];
	sk=d[1];
	sort(d+1,d+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		se[i][1]=se[i-1][1]+1;
	}
	for(int j=2;j<=m;j++){
		if(j%2==1){
			se[1][j]=se[1][j-1]+2*n+1;
			for(int i=2;i<=n;i++) {
				se[i][j]=se[i-1][j]+1;
			}
		}
		
	}
	for(int j=2;j<=m;j++){
		if(j%2==0){
			se[n][j]=se[n][j-1]+1;
			for(int i=n-1;i>=1;i--){
				se[i][j]=se[i+1][j]+1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			se[i][j]=d[se[i][j]];
			if(se[i][j]==sk){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
