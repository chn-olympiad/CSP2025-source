#include <bits/stdc++.h>
using namespace std;
int n,m,k,w,l,h;
int a[10005];
int main(){
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort (a+1,a+1+n*m);
	for (int i=1;i<=n*m;i++){
		if (a[i]==k){
			w=n*m-i+1;
			break;
		}
	}
	l=ceil (w*1.0/n);
	if (l%2==0){
		if (w%n==0){
			h=1;
		}else {
			h=n-w%n+1;
		}
	}else {
		if (w%n==0){
			h=n;
		}else {
			h=w%n;
		}
	}
	cout<<l<<" "<<h;	
	return 0;
}
