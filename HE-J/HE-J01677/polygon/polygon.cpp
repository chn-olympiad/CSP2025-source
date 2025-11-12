#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+100,INF=0x3f3f3f3f3f3f3f3f,mod=998244353;
int n,m;
int a[N],ans;
int c[N];
int pian_n3(){
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	return sum>2*a[n];
}
vector<int> v;
int pian_1(int n){
	int k=n%mod*(n-1ll)%mod;
	int p=2ll;
	int ans=0ll;
	for(int i=3ll;i<=n;i++){
		k=(k*(n-i+1ll)%mod),p=p*i%mod;
		int o=k/p;
		ans=(ans+o)%mod;
	}
	return ans%mod;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
	cin>>a[i];
	c[i]=c[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	if(n==3)cout<<pian_n3()<<"\n";
	else{
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			v.push_back(a[i]);
		}
	}
	cout<<pian_1(v.size());
	}
	return 0;
}
