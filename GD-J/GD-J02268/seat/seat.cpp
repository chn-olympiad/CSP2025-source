#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
int a[1005][1005],A[1005],R;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>A[i];
	}
	R=A[1];
	sort(A+1,A+n*m+1);
	int x=n*m;
	for(int i=1;i<=n;i++){
		if(i%2!=0){
			for(int j=1;j<=m;j++){
				a[j][i]=A[x];
				x--;
			}
		}else{
			for(int j=m;j>=1;j--){
				a[j][i]=A[x];
				x--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==R){
				cout<<j<<" "<<i;
				break; 
			}
		}
	}
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	return 0;
} 
