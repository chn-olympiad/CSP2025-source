#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x;
int mj(int x){
	for(int i=1;i<=n*m;i++){
		if(a[i]==x) return i;
	}
	return 0;
}
bool cmp(const int &x,const int &y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	int pos=mj(x);
	int r,c=ceil(pos*1.0/n);//t---奇数1往下，偶数0往上
	int t=c&1;
	if(t==1){
		if(pos%n!=0) r=pos%n;
		else r=n;
	}
	else if(t==0){
		if(pos%n!=0) r=n-pos%n+1;
		else r=1;
	}
	cout<<c<<' '<<r;
	return 0;
}
