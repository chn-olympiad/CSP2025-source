#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
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
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	int id=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			id=i;
			break;
		}
	}
//	cout<<"id="<<id<<endl;
	int c;
	if(id%n==0){
		c=id/n;
	}else{
		c=id/n+1;
	}
//	cout<<"c="<<c<<endl;
	int r=id%n;
//	cout<<"r="<<r<<endl;
	if(r==0)r=n;
	if(c%2==1){
		cout<<c<<" "<<r<<endl;
	}else{
		cout<<c<<" "<<n-r+1<<endl;
	}
	return 0;
}
