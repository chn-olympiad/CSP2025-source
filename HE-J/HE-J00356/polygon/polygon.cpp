#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=114514;
const int mod=998244353;
int c(int n,int m){
	int ans=1;
	for(int i=m+1;i<=n;i++) ans*=i;
	for(int i=1;i<=n-m;i++) ans/=i;
	return ans%mod;
}
int n,a[N],maxx,anss;
bool ar=true;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		anss+=a[i];
		if(a[i]!=a[0]) ar=false;
	}
	if(n==3){
		if(anss>maxx*2) cout<<1;
		else cout<<0;
	}
	if(ar=true){
		int ans=0;
		for(int tmp=3;tmp<=n;tmp++){
			ans+=c(n,tmp);
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
}
