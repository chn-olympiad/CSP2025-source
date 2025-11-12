#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[110];
bool cmp(int d,int b){
	return d>b;
}

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int f=0,n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	f=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==f){
			f=i;
		}
	}
	int c=0,r=0;
	if(f%n==0){
		c=f/n;
	}else{
		c=f/n+1;
	}
	if(c%2==1){
		if(f%n==0){
			r=n;
		}else{
			r=f%n;
		}
	}else{
		r=n-f%n+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
