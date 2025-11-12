#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int32_t main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	int n,m;
	cin>>n>>m;
	int q=n*m;
	int b[q+10],a[m+10][n+10];
	for(int i=1;i<=q;i++){
		cin>>b[i];
	}
	int s=b[1];
	int g=1;
	for(int i=1;i<=q;i++){
		for(int j=1;j<=q;j++){
			if(b[i]>b[j]){
				swap(b[i],b[j]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[i][j]=b[g];
				g++;
			}
		}
		else {
			for(int j=n;j>=1;j--){
				a[i][j]=b[g];
				g++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==s) {
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
//#Shang4Shan3Ruo6Shui4
