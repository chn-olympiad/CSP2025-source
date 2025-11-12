#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],mx,ans;
void df(int c,int m,int s,int d){
	bool f=(s>2*m&&d>=3);
	if(f) ans=(ans+1)%mod;
//	cout<<c<<' '<<m<<' '<<s<<' '<<ans<<endl;
	if(c==n) return ;
	for(int i=c+1;i<=n;i++){
		df(i,max(m,a[i]),s+a[i],d+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	df(0,0,0,0);
	cout<<ans;
	return 0;
}

