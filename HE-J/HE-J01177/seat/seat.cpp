#include<bits/stdc++.h>
using namespace std;
const int maxn=103;
int n,m,ans,a[maxn][maxn];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	ans=a[1][1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]<a[i][j+1]){
				swap(a[i][j],a[i][j+1]);
			}
			else if(a[i][j]<a[i+1][j]){
				swap(a[i][j],a[i+1][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans==a[i][j]){
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}
