#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int a1=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==a1){
			a1=i+1;
			break;
			}
	}
	int c=ceil(1.0*a1/n);
	cout<<c<<" ";
	if(c%2==0){
		if(a1%n==0)cout<<1;
		else cout<<n-a1%n+1;
	}else if(a1%n==0)cout<<n;
	else cout<<a1%n;
	
}
