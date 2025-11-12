#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],t,x,h,l;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(t==a[i]){
			x=n*m-i+1;
			break;
		}
	}
	l=(x-1)/n+1;
	if(l%2==1){
		h=x-n*(l-1);
	}
	else{
		h=n-x%n+1;
	}
	cout<<l<<" "<<h;
	return 0;
}
