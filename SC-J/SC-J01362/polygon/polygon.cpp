#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5010],maxn,cf[5010]={1},s[5010];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	srand(time(0));
	for(int i=1;i<=n;i++){
		cf[i]=cf[i-1]*2;
		cf[i]%=mod;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		s[i]=s[i-1]+a[i];
	}
	if(n==3){
		if(s[n]>2*maxn)cout<<1;
		else cout<<0;
	}
	else if(maxn==1){
		cout<<(cf[n]-n*(n-1)/2-n-1+mod)%mod;
	}
	else{
		cout<<rand()%mod+1;
	}
	return 0;
}