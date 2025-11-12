#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,wz,xm;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}xm=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==xm){
			wz=n*m-i+1;
		}
	}int lie=(wz%n==0?wz/n:wz/n+1),s=wz-wz/n*n;
	cout<<lie<<" "<<(lie%2==0?s+1:(s==0?n-s:s));
	return 0;
}
