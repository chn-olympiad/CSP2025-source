#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,ans=0,max_a=-1;
vector<int> a;
vector<int> p;
int C(int m,int n){
	return p[m]/(p[m-n-1]*p[n]%mod)%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	a.resize(n+1,0);
	p.resize(n+1,0);
	p[0]=p[1]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		max_a=max(max_a,a[i]);
		p[i]=i*p[i-1]%mod;
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>max_a*2){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	if(max_a==1){
		for(int i=3;i<=n;i++){
			ans=(ans+C(n,i))%mod;
		}
	}
	cout<<ans%mod;
	return 0;
}
