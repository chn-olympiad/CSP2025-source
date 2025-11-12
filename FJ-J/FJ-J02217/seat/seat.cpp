#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int k=a[1],xb=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++) {
		if(a[i]==k){
			xb=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(i*n-n+1==xb && i%2==1) {
			cout<<i<<" "<<1;
			return 0;
		}
		else if(i*n==xb && i%2==0) {
			cout<<i<<" "<<1;
			return 0;
		}
		else if(i*n-n+1==xb && i%2==0) {
			cout<<i<<" "<<n;
			return 0;
		}
		else if(i*n==xb && i%2==1) {
			cout<<i<<" "<<n;
			return 0;
		}
		else if(i*n>xb && n*(i-1)<xb) {
			if(i%2==0) cout<<i<<" "<<n-xb%n+1;
			else cout<<i<<" "<<xb%n;
		}	
	}
	return 0;
}
