#include<bits/stdc++.h>
using namespace std;
int ka[10007],k,pi=1,x,y;
int co(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>k;
	ka[1]=k;
	for(int i=2;i<=n*m;i++){
		cin>>ka[i];
	}
	sort(ka+1,ka+n*m+1,co);
	for(int i=1;i<=n*m;i++){
		if(ka[i]==k) pi=i;
	}
	if(pi%n){
		x++;
	}
	x+=pi/n;
	if(x%2){
		y=pi%n;
		if(y==0)y=n;
	}
	else{
		y=n-pi%n+1;
	}
	cout<<x<<" "<<y;
	return 0;
} 
