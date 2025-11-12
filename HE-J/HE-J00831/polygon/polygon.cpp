#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD=998244353;
ll ans=0,l[5100];
bool cmp(int x,int y){return x>y;}
ll C(int m,int n){
	ll ans=1;
	for(int i=n;i>=n-m+1;i--) ans*=i;
	for(int i=m;i>=1;i--) ans/=i;
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n; cin>>n;
	for(int i=1;i<=n;cin>>l[i++]);
	for(int i=3;i<=n;i++) ans=(ans+C(i,n))%MOD;
	cout<<ans;
	return 0;
} //15~20<=20pts (max_ai<=1)



//QwQ kkk
