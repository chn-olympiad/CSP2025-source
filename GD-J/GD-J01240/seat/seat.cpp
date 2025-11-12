#include<bits/stdc++.h>
using namespace std;
struct S{
	bool s;
	int k;
}a[105];
int n,m;
bool cmp(S x,S y){
	return x.k>y.k;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].k;
	}
	a[1].s=1;
	sort(a+1,a+n*m+1,cmp);
	int t=-1;
	for(int i=1;i<=n*m;i++){
		if(a[i].s){
			t=i;
			break;
		}
	}
	int y=ceil(t*1.0/n),x=t-(y-1)*n;
	if(y%2==0){
		x=n-x+1;
	}
	cout<<y<<" "<<x;
	return 0;
}
