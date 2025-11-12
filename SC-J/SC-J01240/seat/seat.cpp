#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b,r,l,h;
int p(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}b=a[0];
	sort(a,a+m*n,p);
	for(int i=0;i<n*m;i++){
		if(a[i]==b){
			r=i;
			break;
		}
	}l=r/n+1;
	if(l%2!=0){
		h=r%n+1;
	}else{
		h=n-r%n;
	}cout<<l<<' '<<h;
	return 0;
}