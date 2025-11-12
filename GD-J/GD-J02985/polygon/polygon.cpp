#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,mod=998244353;
long long n,a[N],ans;
void work(int k,int h){
	if(k>n)return;
	if(h>a[k]&&k>2)ans=(ans+1)%mod;
	work(k+1,h+a[k]);
	work(k+1,h);
}int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	work(1,0);
	cout<<ans<<"\n";
	return 0;
}
