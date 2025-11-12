#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100+50];
int b[101][101];
bool cmp(int c,int d) {
	return c>d;
}
int ans;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	int k=1;
	for(int i=1; i<=m; i++) {
		if(i%2!=0) {	
			for(int j=1; j<=n; j++) {
				b[i][j]=a[k];
				k++;
			}
		} else {
			if(i%2==0) {
				for(int j=n; j>=1; j--) {
					b[i][j]=a[k];
					k++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==ans){
				cout<<i<<" "<<j;
				break;
			}
		}
	}
	return 0;
}
