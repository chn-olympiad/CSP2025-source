#include <bits/stdc++.h>
using namespace std;
int n,m,a[10001],e,r=1,u,x,y,f;
bool hdhd(int s1d,int s2d){
	return s1d>s2d;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	e=n*m;
	for(int i=1;i<=e;i++){
		cin>>a[i];
	}
	u=a[1];
	sort(a+1,a+1+e,hdhd);
	while(a[r]!=u){
		r++;
	}
	x=(r-1)/n+1;
	if(x%2==1){
		y=r%n;
		if(y==0) y=n;
	}else{
		y=n-(r%n)+1;
		if(y==n+1) y=1;
	}
	cout<<x<<" "<<y;
	return 0;
}
