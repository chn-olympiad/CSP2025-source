#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int m,n,a[105];
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}int a1=a[1];
	sort(a+1,a+n*m+1);
	int q=m*n;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[q]==a1){
					cout<<i<<" "<<j;
					return 0;
				}q--;
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[q]==a1){
					cout<<i<<" "<<j;
					return 0;
				}q--;
			}
		}
	}
}