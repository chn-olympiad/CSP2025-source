#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],t[110],c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int b=n*m;
	for(int i=1;i<=b;i++){
		cin>>a[i];
	}
	int d=a[1];
	sort(a+1,a+b+1);
	for(int i=b;i>=1;i--) t[b-i+1]=a[i];
	for(int i=1;i<=b;i++){
		if(t[i]==d){
			c=ceil(i/(n*1.0));
			r=i%n;
			if(c%2==1){
				if(r==0) r=n;
			}
			else {
				if(r==0) r=1;
				else r=n+1-r;
			}
			break;
		}
	}
	cout<<c<<" "<<r;
}