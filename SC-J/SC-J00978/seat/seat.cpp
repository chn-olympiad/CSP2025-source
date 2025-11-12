#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,w,l,h,q;
	cin>>n>>m>>a[1];
	int r=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==r){
			q=i;
			break;
		}
	}
	w=n*m-q+1;
	if(w%n==0){
		l=w/n;
	}
	else{
		l=w/n+1;
	}
	if(l%2==1){
		if(w<=n){
			h=w;
		}
		else{
			h=w%n;
		}
	}
	else{
		h=n-w%n+1;
	}
	cout<<l<<" "<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}