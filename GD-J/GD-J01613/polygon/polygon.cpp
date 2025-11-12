#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],q[5005];
long long da[5005],ans,mod=998244353;
bool cmp(long long L,long long R){
	return L>R;
}
void f(long long x,long long z,long long mx){
	if(z>mx*2){
		ans+=da[n-x+1];
		ans%=mod;
		return;
	}
	for(int i=x;i<=n;i++) f(i+1,z+a[i],mx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	da[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		da[i]=da[i-1]*2;
		da[i]%=mod;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) f(i+1,a[i],a[i]);
	cout<<ans;
	return 0;
}
