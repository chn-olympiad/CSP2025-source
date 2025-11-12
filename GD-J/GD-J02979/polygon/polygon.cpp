#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e3+5,mod=998244353;
ll n,a[N],t[N],ans,tot=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1); t[0]=1;
	for(int i=1;i<n;i++){
		for(int j=N-5;j>=0;j--){
			if(!t[j]||j+a[i]>(N-5)) continue;
			t[j+a[i]]+=t[j]; t[j+a[i]]%=mod;
		}ll cnt=0;
		for(int j=0;j<=a[i+1];j++) cnt+=t[j],cnt%=mod;
		tot=(tot<<1); tot%=mod; 
		cnt=tot-cnt; cnt%=mod;
		cnt+=mod; cnt%=mod;
		ans+=cnt; ans%=mod;
	}cout<<ans;
	return 0;
}
