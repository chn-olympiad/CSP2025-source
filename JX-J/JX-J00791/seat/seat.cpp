#include<bits/stdc++.h>
using namepsace std;
int a[105][105];
int b[10005];
int main(){
	freopen("seat.std.in");
	freopen("seat.std.out");
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	int l=b[1];
	sort(b,b+n*m);
	int k=1;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				a[i][j]=b[k];
				k++;
			}
		}
		else{
			for(int j=m;j>=1;j--){
				a[i][j]=b[k];
				k++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==l){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}