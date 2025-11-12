#include<bits/stdc++.h>
using namespace std;

int n,m,s,r,x;
int a[101];

bool compare(int a,int b){
	return a>b;
}

void solve(int f){
	cout<<(f+m-1)/m<<" ";
	bool ds=0;
	if(((f+m-1)/m)%2) ds=1;
	if(ds){
		if(f%n) cout<<f%n;
		else cout<<n;
	}else{
		if(f%n) cout<<n-f%n+1;
		else cout<<1;
	}
	return;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	s=n*m;
	cin>>a[1];
	r=a[1];
	for(int i=2;i<=s;i++){
		cin>>a[i];
		if(a[i]>r) ++x;
	}
	sort(a+1,a+s+1,compare);
	solve(x+1);
	return 0;
}
