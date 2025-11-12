#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll mod=998244353ll;
ll d[505][50005],ans,c[50005];
int n,a[505],sum;
void add(ll&x,const ll r){
	x=(x+r)%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)
	cin>>a[i],sum+=a[i];
	sort(a+1,a+n+1);
	c[0]=1ll;
	for(int i=1;i<=n;++i){
		for(int k=a[i];k<=sum;++k){
			add(d[i][k],c[k-a[i]]);
			if(2*a[i]<k)add(ans,d[i][k]);
		}
		for(int k=a[i];k<=sum;++k){
			add(c[k],d[i][k]);
		}
	}
	cout<<ans<<"\n";
}	

