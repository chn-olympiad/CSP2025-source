#include <bits/stdc++.h>
using namespace std;

int n,m;
int a;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	
	cin>>a;
	
	int cnt=1;
	for(int i=2;i<=n*m;i++){
		int x;
		cin>>x;
		if(a<x)cnt++;
	}
	
	int c,r;
	c=(cnt-1)/n+1;
	if(c%2!=0){
		r=cnt-(c-1)*n;
	}
	else{
		int tmp=cnt-(c-1)*n;
		r=n-tmp+1; 
	}

	cout<<c<<' '<<r<<'\n';
	return 0;
}
