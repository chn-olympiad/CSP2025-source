#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int R=a[1],indx;
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==R){
			indx=n*m-i+1;
			break;
		}
	}
	int c,r=indx%n;
	if(indx%n==0){
		c=indx/n;
	}else{
		c=indx/n+1;
	}
	if(r==0){
		if(c%2==0){
			r=1;
		}else{
			r=n;
		}
	}else{
		if(c%2==0){
			r=n-r+1;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
