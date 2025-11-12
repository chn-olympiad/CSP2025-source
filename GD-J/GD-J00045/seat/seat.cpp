#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,m,a[N][N],p[N*N],po,r,cnt;
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>p[++po];
		}
	}
	r=p[1];
	sort(p+1,p+po+1,greater<int>());
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				a[j][i]=p[++cnt];
			}
		}else{
			for(int j=n;j>=1;j--){
				a[j][i]=p[++cnt];	
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==r){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
