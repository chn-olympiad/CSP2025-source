#include<bits/stdc++.h>
using namespace std;
int a,n,m,q,w=1,e;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a;
		if(i==1) q=a;
		if(a>q) w++;
	}
	if(w%n) e=w/n+1;
	else e=w/n;
	cout<<e<<" ";
	if(e%2==0){
		if(w%n) cout<<n-w%n+1;
		else cout<<1;
	}else{
		if(w%n) cout<<w%n;
		else cout<<n;
	}
	return 0;
}
