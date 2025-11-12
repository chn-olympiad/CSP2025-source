#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],R,pm,c,r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int gs=n*m;
	for(int i=1;i<=gs;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+gs+1,cmp);
	for(int i=1;i<=gs;i++){
		if(a[i]==R) pm=i;
	}
	if(pm%(2*n) == 0){
		r=1;
	}
	else if(pm%(2*n) <= n && pm%(2*n) != 0){
		r=pm%(2*n);
	}
	else{
		r=2*n-pm%(2*n)+1;
	}
	if(pm%n == 0){
		c=pm/n;
	}
	else{
		c=pm/n+1;
	}
	if(n==1) cout<<pm<<" "<<1;
	else if(m==1) cout<<1<<" "<<pm;
	else cout<<c<<" "<<r;//c列r行,n行m列 
	return 0;
}

