#include <bits/stdc++.h>
using namespace std;
int main(){
	int a[11][11],b[110];
	int n,m,k,cnt=1;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>k;
	b[0]=k;
	for(int i=1;i<m*n;i++){
		cin>>b[i];
	}
	for(int i=0;i<m*n;i++){
		for(int j=0;i<m*n-i-1;j++){
			if(b[j]<b[j+1]){
				swap(b[j],b[j+1]);
			}
		}	
	}
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				a[i][j]=b[i*cnt];
				cnt++;
			}
		}else{
			for(int j=m;j>=1;j--){
				a[i][j]=b[i*cnt];
				cnt++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==k){
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}
