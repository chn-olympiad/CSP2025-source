#include <bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
int n,m,a[110],b[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int realr;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			realr=i;
		}
	}
	int realn,realm;
	if(realr%n!=0){
		realm=realr/n+1;
	}
	else if(realr%n==0){
		realm=realr/n;
	}
	if(realm%2==0){
		if(realr%n!=0){
			realn=n-(realr%n)+1;
		}
		else{
			realn=1;
		}
	}
	if(realm%2!=0){
		if(realr%n!=0){
			realn=realr%n;
		}
		else if(realr%n==0){
			realn=n;
		}
		else if(realr<n){
			realn=realr;
		}
	}
	cout<<realm<<" "<<realn;
	return 0;
}

