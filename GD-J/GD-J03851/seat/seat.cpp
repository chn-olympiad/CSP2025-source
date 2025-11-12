#include <bits/stdc++.h>
using namespace std;
int a[105];
int n,m,xr,ans,p,l,r;
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
	xr=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==xr){
			p=i;
			break;
		}
	}
	if(p%n==0){
		l=p/n;
	}else{
		l=p/n+1;
	}
	r=p%n;
	if(r==0)r=n;
	if(l%2==0){
		r=n-r+1;
	}
	cout<<l<<" "<<r;
	return 0;
}
