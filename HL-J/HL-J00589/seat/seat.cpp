#include<bits/stdc++.h>
using namespace std;
int n,m;
int sc[150];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>sc[i];
	}
	int t=sc[1],mc=1;
	for(int i=1;i<=n*m;i++){
		if(sc[i]>t) mc++;
	}
	int c,r;
	if(mc%n==0) c=mc/n;
	else c=mc/n+1;
	if(c%2==0){
		if(mc%n==0){
			r=1;
		}
		else r=n+1-mc%n;
	}
	else{
		if(mc%n==0){
			r=n;
		}
		else r=mc%n;
	}
	cout<<c<<" "<<r;
	return 0;
}
