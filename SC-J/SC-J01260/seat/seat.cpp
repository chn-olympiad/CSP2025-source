#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int a[105],a1;
int main(){
	freopen("seat.in ","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a1=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==a1){
			k=n*m-i+1;
		}
	}
	int h=0,l=0;
	if(k%n!=0){
		h=k/m+1;
	}
	else{
		h=k/m;
	}
	if(k%n==0) l=m;
	else l=k%n;
	if(h%2==1){
		cout<<h<<' '<<l;
	}
	else{
		cout<<h<<' '<<m-l+1;
	}
	return 0;
}
