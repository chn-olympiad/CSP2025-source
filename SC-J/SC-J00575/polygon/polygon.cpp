#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
int n,a[5005];
ll f[5005],ans,p[5005];
void add(int x,ll y){
	x++;
	for(;x<=5001;x+=x&-x){
		f[x]=(f[x]+y)%mod;
	}
}
ll get(int x){
	x++;
	ll sum=0;
	for(;x;x-=x&-x){
		sum=(sum+f[x])%mod;
	} 
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	p[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]=p[i-1]*2%mod;
	}
	sort(a+1,a+n+1);
	add(0,1);
	for(int i=1;i<=n;i++){
		ans=(ans+p[i-1]-get(a[i])+mod)%mod;
		for(int j=5000;j>=a[i];j--){
			add(j,(get(j-a[i])-get(j-a[i]-1)+mod)%mod);
		}
	}
	cout<<ans;
	return 0;
}