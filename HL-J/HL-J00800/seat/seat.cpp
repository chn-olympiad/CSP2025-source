#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101],z,q;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		z=a[1];
		for(int j=1;j<n*m;j++){
			if(a[i]>a[j-1]){
			q=a[j-1];
			a[j-1]=a[i];
			a[i]=q;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(a[j]==z)cout<<i<<' '<<j+1;i=n*m+1;break;
}}
	return 0;
}
