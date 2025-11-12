#include<bits/stdc++.h>
using namespace std;
const int nx=15;
int m,n;
int a[nx*nx],r,xs;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=m*n; i++){
		cin>>a[i];
	}r=a[1];
	sort(a+1,a+n*m+1);
	int sum=0;
	for(int i=n*m; i>0; i--){
		sum++;
		if(a[i]==r) {
			xs=sum;
			break;
		}
	}
	if(xs==n*m){
		if(m%2==0){
			cout<<m<<" "<<1;
		}else{
			cout<<m<<" "<<n;
		}return 0;
	}if(xs==1){
		cout<<1<<" "<<1;
		return 0;
	}for(int i=1; i<=m; i++){
		if(i*n<xs) continue;
		int x;
		if(i%2==1) {
			x=xs-(i-1)*n;
			cout<<i<<" "<<x;
			break;
		}else if(i%2==0){
			x=i*n-xs+1;
			cout<<i<<" "<<x;
			break;
		}
	}
	return 0; 
}