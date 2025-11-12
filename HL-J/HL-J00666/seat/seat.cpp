#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c;
int ss(int q,int n){
	if(q%n==0)return q/n;
	else return q/n+1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=2;i<=n*m;i++){
		cin>>b;
		if(b>a)c++;
	}
	if(c<n)cout<<1<<' '<<c+1;
	else if(((c+1)/n)%2==0){
		cout<<ss(c+1,n)<<' '<<(c+1)%n;
	}
	else {
		cout<<ss(c+1,n)<<' '<<n+1-(c+1)%n;
	}
	return 0;
}
