#include<bits/stdc++.h>
using namespace std;
const int NN=15;
int a[NN*NN],pos[NN][NN];
int n,m,sc;
bool cmp(int A,int B) {
	return A>B;
}
int main() {
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	sc=a[1];
	sort(a+1,a+1+n*m,cmp);
	int cnt=1;
	for(int j=1; j<=m; j++) {
		if(j%2==1) {
			for(int i=1; i<=n; i++) {
				pos[i][j]=a[cnt];
				cnt++;
			}
		} else {
			for(int i=n; i>=1; i--) {
				pos[i][j]=a[cnt];
				cnt++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(pos[i][j]==sc){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	return 0;
}

