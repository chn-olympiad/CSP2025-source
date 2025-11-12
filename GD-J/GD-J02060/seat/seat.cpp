#include <bits/stdc++.h>
using namespace std;
int a[110];
int ans[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int p=n*m;
	for(int i=1;i<=p;i++){
		cin>>a[i];
	}
	int self = a[1];
	for(int i=1;i<=p;i++){
		for(int j=1;j<=p-1;j++){
			if(a[i]<a[i+1]){
				swap(a[i],a[i+1]);
			}
		}
	}
	int pos = 1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				ans[j][i] = a[pos];
				pos++;
			}
		}
		else{
			for(int k=n;k>=1;k--){
				ans[k][i] = a[pos];
				pos++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(ans[i][j]==self){
				cout<<j<<' '<<i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
