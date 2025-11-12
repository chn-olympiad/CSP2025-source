#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long a[105][105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	int any=a[1][1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]<a[i][j+1])swap(a[i][j],a[i][j+1]);
		}
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(any==a[i][j]){
				cout<<i<<" "<<j;
				break;
			}
		}
	}
	return 0;
}