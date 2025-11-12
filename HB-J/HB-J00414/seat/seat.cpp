#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int g[17][17];
int a[400];
bool cmp(int a,int b){return a>b;}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) cin>>a[i];
	int t=a[1];
	sort(a+1,a+n*m+1,cmp);
	int k=1;
	for(int i=1; i<=m; i++){
		if(i%2==0){
			for(int j=n; j>=1; j--){g[j][i]=a[k++];}
		}
		else{
			for(int j=1; j<=n; j++){g[j][i]=a[k++];}
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(g[i][j]==t){cout<<j<<" "<<i; return 0;}
		}
	}
	return 0;
}
