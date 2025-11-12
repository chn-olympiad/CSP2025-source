#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[10007],c,r,ans;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	int R=a[1];
	sort(a+1,a+1+m*n);
	for(int i=m*n;i>=1;i--){
		if(a[i]==R) { ans=m*n-i+1;break;}
	}
	if(ans%n==0){
		r=n;
		c=(ans/n);
	}else{
		c=(ans/n)+1;
		if(c%2==1) r=ans%n;
		if(c%2==0) r=n-ans%n+1;
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
2 2
98 99 100 97
*/
