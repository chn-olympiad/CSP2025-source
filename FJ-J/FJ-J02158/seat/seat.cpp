#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
int a[105];
bool cp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int s=a[1],cr;
	sort(a+1,a+n*m+1,cp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			cr=i;
			break;
		}
	}
	if(cr%n==0){
		c=cr/n;
		if(c%2==1)	r=n;
		else	r=1;
	}
	else{
		c=cr/n+1;
		if(c%2==1){
			r=cr%n;
		}
		else
			r=n-(cr%n)+1;
	}
	cout<<c<<' '<<r;
	return 0;
}
