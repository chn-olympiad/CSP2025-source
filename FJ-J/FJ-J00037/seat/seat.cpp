#include<bits/stdc++.h>
using namespace std;
int n,m,s[20][20],a[400],cj,wz,c,r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cj=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==cj) wz=i;
	}
	int pp=ceil(wz*1.0/n);
	if(pp%2==1){
		c=ceil(wz*1.0/n);
		if(wz%n==0) r=n;
		else r=wz%n;
	}else if(pp%2==0){
		c=ceil(wz*1.0/n);
		if(wz%n==0) r=1;
		else r=n+1-wz%n;
	}
	cout<<c<<" "<<r;
	return 0;
}
