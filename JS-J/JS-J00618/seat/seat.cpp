#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int n,m,l;
int a[120];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			l=a[i];
		}
	}
	sort(a,a+n*m+1);
	reverse(a,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(l==a[i]){
			if(i%m==0){
				if(i/m%2==1)cout<<i/m<<" "<<n;
				else cout<<i/m<<" "<<1;
			}else{
				if((i/m+1)%2==1)cout<<i/m+1<<" "<<i%m;
				else cout<<i/m+1<<" "<<n-i%m+1;
			}
		}
	}
	return 0;
}
