#include <bits/stdc++.h>
using namespace std;
int n,m,a[105];
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
	int id=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==id){
			id=i-1;
			break;
		}
	}
	int c=id/n+1;
	if(c%2==1){
		cout<<c<<' '<<id%n+1;
	}
	else{
		cout<<c<<' '<<n-id%n;
	}
	return 0;
}
