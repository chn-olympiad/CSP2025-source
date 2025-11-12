#include<bits/stdc++.h>
using namespace std;

const int N=15;

int n,m,x,a[N*N],seat[N][N],pos;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	x=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int j=1;j<=m;j++){
		if(j&1){
			for(int i=1;i<=n;i++){
				seat[i][j]=a[++pos];
				if(seat[i][j]==x){
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}else{
			for(int i=n;i>=1;i--){
				seat[i][j]=a[++pos];
				if(seat[i][j]==x){
					cout<<j<<' '<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}
