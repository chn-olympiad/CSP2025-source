#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,a[N],p,z,l,h;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==p) z=i;
	}
	l=ceil(1.0*z/n);
	h=z-(l-1)*n;
	if(l%2==0){
		h=n-h+1;
	}
	cout<<l<<' '<<h;
	return 0;
}
