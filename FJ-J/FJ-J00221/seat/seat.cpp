#include<bits/stdc++.h>
using namespace std;
int a[110];
int ygg(int l,int r,int cnt){
	bool f=1;
	while(f){
		if(a[l+(r-l)/2]==cnt){
			l+=(r-l)/2;
			f=0;
		}else if(a[l+(r-l)/2]>cnt) r-=(r-l)/2+1;
		else l+=(r-l)/2+1;
	}
	return l;
}
int mark(int l,int r,int n){
	if(l%n==0){
		r=l/n;
	}else r=l/n+1;
	return r;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	int l=1,r=n*m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cnt=a[1];
	sort(a+1,a+r+1);
	l=n*m+1	-ygg(l,r,cnt);
	r=mark(l,r,n);
	cout<<r<<" ";
	if(r%2==0) cout<<n-l+n*(r-1)+1;
	else cout<<l-n*(r-1);
	return 0;
}

