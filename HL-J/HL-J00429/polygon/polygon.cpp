#include <bits/stdc++.h>

using namespace std;
int n,a[5000+500],num;
void f(int zgs,int zd,int xh,int zs){
	if (xh>n){
		if (zgs>=3 && zs>2*zd){
			num++;
			num%=998244353;
		}
		return;
	}
	f(zgs+1,a[xh],xh+1,zs+a[xh]);
	f(zgs,zd,xh+1,zs);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	f(0,0,1,0);
	cout<<num;
	return 0;
}
