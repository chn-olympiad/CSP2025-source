#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+n*m+1);
	int i=1;
	for(i=1;i<=m*n;i++){
		if(a[i]==s) break;
	}
	i=n*m-i+1;
	c=i%n==0?i/n:i/n+1;
	if(c%2==1){
		if(i%n==0){
			r=n;
		}else r=i%n;
	}else if(c%2==0){
		if(i%n==0){
			r=1;
		}else r=n-i%n+1;
	}
	cout<<c<<" "<<r;
	return 0;
}