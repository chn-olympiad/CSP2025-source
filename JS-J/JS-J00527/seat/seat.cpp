#include<bits/stdc++.h>
using namespace std;
int n,m;
int x[105];
int a[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>x[i];
	}
	int q=x[1];
	sort(x+1,x+n*m+1);
	int k=n*m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=x[k];
			k--;
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=m;j>=1;j--){
			if(a[i][j]==q){
				cout<<j<<" "<<i<<endl;
				return 0;
			}
		}
	}
	return 0;
}
