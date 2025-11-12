#include<bits/stdc++.h>
#define endl '\n'
#define int long long 
using namespace std;
const int N=1e2+5;
int n,m;
int a[N];
int ans[N][N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int tar=a[1];
	sort(a+1,a+m*n+1);	
	int w=0;int v=1;int d=1;
	int coot=n*m;
	while(coot>=1){
		if(w==n&&d==1){
			v++;d=-1;
		}else if(w==1&&d==-1){
			v++;d=1;
		}else{
			w+=d;
		}
		ans[w][v]=a[coot];
		coot--;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<tar<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans[i][j]==tar){
				cout<<j<<" "<<i; 
				return ;
			}
		}
	}
	return ;
}
signed main(){
	std::ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	solve();
	
	return 0;
}	