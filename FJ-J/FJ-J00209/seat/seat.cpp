#include<bits/stdc++.h>
using namespace std;
int a[101],b[10][10];
int main(){
	freopen("r","seat.in",stdin);
	freopen("w","seat.out",stdout);
	int n,m,t;
	cin>>n>>m;
	cin>>a[0];
	t=a[0];
	int xb=n*m-1;
	for(int i=1;i<n*m;i++) cin>>a[i];
	sort(a+0,a+n*m);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				b[i][j]=a[xb];
				if(a[xb]==t) cout<<i<<' '<<j;
				xb--;
			}
		}else{
			for(int j=n;j>=1;j--){
				b[i][j]=a[xb];
				if(a[xb]==t) cout<<i<<' '<<j;
				xb--;
			}
		}	
	}
    return 0;
}

