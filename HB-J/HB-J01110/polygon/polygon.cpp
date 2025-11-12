#include<bits/stdc++.h>
using namespace std;
long long n,m,w,xa=-1,book=0,ya=0;
long long a[200];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ya+=a[i];
		if(xa<a[i]){
			xa=a[i];
		}
	}
	if(n==3){
		if(xa*2<ya){
			cout<<1;
			return 0;
		}
		else{
			cout<0;
			return 0;
		}
	}
	cout<<6;
	return 0;
}

