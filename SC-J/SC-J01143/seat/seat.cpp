#include<bits/stdc++.h>
using namespace std;
int A[15][15];
int B[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>B[i];
	int R;
	R=B[1];
	int k=1;
	sort(B+1,B+n*m+1);
	reverse(B+1,B+n*m+1);
	for(int j=1;j<=m;j++){
		if(j%2==0){
			for(int i=n;i>=1;i--){
				A[i][j]=B[k];
				k++;
			}
		}else{
			for(int i=1;i<=n;i++){
				A[i][j]=B[k];
				k++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(A[i][j]==R){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
