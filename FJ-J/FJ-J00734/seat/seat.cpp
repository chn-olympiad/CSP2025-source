#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int n,m,a[N],q,b[20][20],s;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	q=n*m;
	for(int i = 1; i<=q; i++) {
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+1+q);
	int k = q;
	while(k>=1) {
		for(int i = 1; i<=n; i++) {
			if(i%2!=0) {
				for(int j =1; j<=m; j++) {
					b[i][j]=a[k];
					k--;
				}
			}else{
				for(int j =m; j>=1; j--) {
					b[i][j]=a[k];
					k--;
				}
			}
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(b[i][j]==s){
				cout<<i<<" "<<j; 
				return 0;
			}
		}
	}
	return 0;
}
