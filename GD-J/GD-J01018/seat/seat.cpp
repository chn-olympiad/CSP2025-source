#include<bits/stdc++.h>
#define ll long long
#define y1 y114514
using namespace std;
const int N=15;
int a[N*N];
int g[N][N];
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w".stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int t=1;
	for(int i=1;i<=n;i++){
		if(i&1){
			for(int j=1;j<=m;j++){
				g[j][i]=a[t++];
			}
		}
		else {
			for(int j=m;j>=1;j--){
				g[j][i]=a[t++];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(g[i][j]==r){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
/*
I AK CSP-J! 
3 3
94 95 96 97 98 99 100 93 92

1.1 1.2 1.3 
2.3 2.2 2.1 
3.1 3.2 3.3
*/
