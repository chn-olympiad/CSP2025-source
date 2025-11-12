#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=50;
int n,m,d;
int a[N*N];
int b[N][N];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	d=a[1];
	sort(a+1,a+(n*m)+1,greater<int>());
	int k=1;
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				b[j][i]=a[k];
				k++;
			}		
		}else{
			for(int j=n;j>=1;j--){
				b[j][i]=a[k];
				k++;	
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==d){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
