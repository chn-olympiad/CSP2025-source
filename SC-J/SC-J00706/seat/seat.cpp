#include<bits/stdc++.h>
using namespace std;
int n,m,a[100],q,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	y=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==y){
			q=n*m+1-i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(q<=i*n){
			cout<<i<<" ";
			if(i%2==0){
				cout<<i*n+1-q;
			}else{
				cout<<q-(i-1)*n;
			}
			break;
		}
	}
	return 0;
}