#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5100;
int a[N];
int fac(int a){
	if(a==1)return 1;
	return a*fac(a-1);
}
int Cat(int x,int y){
	return fac(y)/fac(x)%998244353;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		int maxx=max(max(a,b),c);
		int ans1=2*maxx;
		if(a+b+c>ans1)cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
	}else{
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=3;i<=n;i++){
			ans=(ans+Cat(i,n))%998244353;
		}
		cout<<ans<<endl;
		return 0;
	}
}
