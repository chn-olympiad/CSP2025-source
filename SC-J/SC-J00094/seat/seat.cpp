#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[20][20],q,b[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==n){
				cout<<1<<" "<<n;
				return 0;
			}
			else if(i==(n+1)){
				cout<<2<<" "<<n;
				return 0;
			}
			else if(i==2*n){
				cout<<2<<" "<<2*n;
				return 0;
			}
			else if(i==(2*n+1)){
				cout<<3<<" "<<2*n+1;
				return 0;
			}
		}

	}	
	return 0;
}