#include<bits/stdc++.h>
using namespace std;
int n,m,r,cj[999];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	for(int i=2;i<=n*m;i++){
		cin>>cj[i];
	}
	cj[1]=r;
	sort(cj,cj+n*m+1);
	int a;
	for(int i=1;i<=n*m;i++){
		if(cj[i]==r){
			a=n*m-i+1;
			break;
		}
	}
	int h,l;
	if(a%n==0){
		l=a/n;
		if(l%2){
			h=n;
		}else h=1;
	}else{
		l=a/n+1;
		if(l%2){
			h=a%n;
		}else h=n-a%n+1;
	}
	cout<<l<<" "<<h;
	return 0;
}
