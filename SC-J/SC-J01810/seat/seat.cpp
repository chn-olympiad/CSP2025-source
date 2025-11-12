#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],r=1,c=1,opt=1,rk;
int main(){
	freopen("seat.in","r",stdin),freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n>>m; for(int i=1;i<=n*m;i++) cin>>a[i];
	rk=0; for(int i=2;i<=n*m;i++) if(a[i]>a[1]) rk++;
	for(;rk;rk--){
		if(opt==1&&r==n) c++,opt=2; else if(opt==2&&r==1) c++,opt=1;
		else if(opt==1) r++; else r--;
	} return cout<<c<<' '<<r<<endl,0;
}