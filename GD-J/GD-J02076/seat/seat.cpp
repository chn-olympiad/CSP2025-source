#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],r,p;
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
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			p=i;
		}
	}
	
	cout<<((p-1)/n)+1<<" ";
	
	if((((p-1)/n)+1)%2==1){
		if(p%n==0){
			cout<<n;
		}
		else{
			cout<<p%n;
		}
	}
	else{
		if(p%n==0){
			cout<<1;
		}
		else{
			cout<<p%n+1;
		}
	}
	return 0;
}
