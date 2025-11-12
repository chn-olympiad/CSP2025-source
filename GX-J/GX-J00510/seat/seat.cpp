#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[105];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int R=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==R){
			R=n*m-i+1;
			break;
		}
	}
	int c=R/n+1;
	int r=R%n;
	if(r==0){
		r=n;
		c--;
	}
	if(c%2==1){
		cout<<c<<" "<<r;
	}else{
		cout<<c<<" "<<n-r+1;
	}
	return 0;
}
