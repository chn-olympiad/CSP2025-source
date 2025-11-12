#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+5;
const int inf = LLONG_MAX; 
const int mod = 998244353;
bool vis[N],Flag=1;
int a[N],n,ans;
void f1(int w,int cnt,int mx,int sum) {
	if(w>n) {
		if(cnt>=3&&sum>2*mx&&mx>0) ans++;
		ans%=mod;
		return;
	}
	f1(w+1,cnt,mx,sum);
	vis[w]=1;
	f1(w+1,cnt+1,max(a[w],mx),sum+a[w]);
}
void f(int w) {
	int mx=a[w]*2,sum=0;
	for(int i=1;i<=w;i++) {
		sum+=a[i];
	}
	if(sum<=mx) return;
	
}
unsigned __int128 C(int n,int m){
	unsigned __int128 aans=1;
	for(int i=n;i>=n-m;i--){
		aans=aans*i;
	}
	for(int i=1;i<=m;i++){
		aans=aans/i;
	}
	aans%=mod;
	return aans;
}

signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
 	cin>>n;
 	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]!=1) Flag=0;
	}
	if(n<=20){	
		f1(1,0,-inf,0);
		cout<<ans;
	} else if(Flag) {
		for(int i=3;i<=n;i++) {
			ans+=C(n,i);
			ans%=mod;
		}
		cout<<ans;
	} else {
		sort(a+1,a+n+1);
		for(int i=3;i<=n;i++) {
			
		}
	}
	return 0;
}
