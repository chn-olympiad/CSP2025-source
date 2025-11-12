#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m,t,r,xuhao=0;
	cin>>n>>m;
	cin>>r;
	for(int i=1;i<n*m;i++){
		cin>>t;
		if(t>r)xuhao++;
	}
	int lieshu=xuhao/n;
	cout<<lieshu+1<<' ';
	if(lieshu&1)cout<<n-xuhao%n;
	else cout<<xuhao%n+1;
	return 0;
}