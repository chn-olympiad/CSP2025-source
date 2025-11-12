#include<bits/stdc++.h>
using namespace std;
int n,m,a,b[150],t;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>b[++t];
		}
	}
	int g=b[1];
	sort(b+1,b+t+1,cmp);
	for(int i=1;i<=t;i++){
		if(b[i]==g){
			a=i;
			break;
		}
	}
	if(a%n==0){
		a/=n;
		if(a%2==0){
			cout<<a<<' '<<1;
		}else{
			cout<<a<<' '<<n;
		}
	}else{
		int c=a/n+1,r=a%n;
		if(c%2==1){
			cout<<c<<' '<<r;
		}else{
			cout<<c<<' '<<n-r+1;
		}
	}
	return 0;
}
