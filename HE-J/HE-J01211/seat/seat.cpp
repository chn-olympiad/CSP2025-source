#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m,r;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=1;
	for(int i=2;i<=n*m;i++){
		if(a[1]<a[i]){
			r++;
		}
	}
	int c=0;
	if(r%n)c=r/n+1;
	else c=r/n;
	if(c%2==1){
		if(r%n)cout<<c<<' '<<r%n;
		else cout<<c<<' '<<n;
	}else{
		if(r%n)cout<<c<<' '<<n-r%n+1;
		else cout<<c<<' '<<1;
	}
	return 0;
}
