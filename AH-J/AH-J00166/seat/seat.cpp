#include<bits/stdc++.h>
using namespace std;
int n,m,a[100],b,c,d,ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	d=a[1];
	sort(a,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==d){
			ans=n*m-i+1;
			break;
		}
	}
	if(ans==1){
		cout<<1<<' '<<1;
		return 0;
	}
	if(ans/n%2==0) b=ans/n;
	else b=ans/n+1;
	c=ans%n;
	cout<<b<<' ';
	if(c==0){
		if(b%2==0) cout<<1;
		else cout<<n;
	}else if(b%2==0){
		cout<<n-c+1;
	}else{
		cout<<c;
	}
	return 0;
}
