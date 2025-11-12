#include<bits/stdc++.h>
using namespace std;
int a[111];
bool func(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdin);
	int n,m,x=0,c=1,r=1;
	bool f=true;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)x=a[i];
	}
	sort(a+1,a+n*m+1,func);
	for(int i=1;i<=n*m&&a[i]!=x;i++){
		if(f&&r==n){
			c++;
			f=false;
		}else if(!f&&r==1){
			c++;
			f=true;
		}else if(f)r++;
		else r--;
	}
	cout<<c<<" "<<r;
	return 0;
}
