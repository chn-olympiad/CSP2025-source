#include<bits/stdc++.h>
using namespace std;
int m,n,a1,a[300];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a1=a[1];
	sort(a+1,a+1+n*m);
	for(int j=1;j<=n*m;j++){
		if(a[j]==a1){
		int i=n*m-j+1;
			if(i%n==0){
				cout<<((i)/n)<<" ";
				if((i/n)%2==1){
					cout<<n;
				}else{
					cout<<1;
				}
			}else{
				cout<<(i/n)+1<<" ";
				if((i/n)%2==1){
					cout<<n-(i%n)+1;
				}else{
					cout<<i%n;
				}
			}
		}
	}
	return 0;
} 