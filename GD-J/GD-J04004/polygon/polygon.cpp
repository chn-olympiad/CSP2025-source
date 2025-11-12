#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long 
const int T=998244353;
int pre[6000],a[6000],n,d[6000];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=2) { 
		cout<<0;
		return 0; 
	} 
	if(n==3) {
		if(a[1]+a[2]<=a[3]) cout<<0;
		else cout<<1;
		return 0;
	}
	if(a[n]==1){
		int ans=1;
		for(int i=1;i<=n;i++) {
			ans*=2;
			ans%=T;
		}
		ans--;
		ans+=T;
		ans-=((n-1)*n)/2+n;
		ans%=T;
		cout<<ans;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
//don't know how to BaoLi,so I can only PianFen
//Everyone RP++ 

