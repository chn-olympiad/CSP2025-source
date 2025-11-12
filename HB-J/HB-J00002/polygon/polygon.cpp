#include <bits/stdc++.h>

using namespace std;

const int N=5005;
int a[N],b[N];
int n,ans;

bool cmp(int x,int y){
	return x<y;
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) b[i]+=a[i-1]+a[i];
	for(int i=1;i<=n-2;i++)
		for(int j=i+2;i<=n;i++)
			if((b[j]-b[i])/2>a[j]){
				ans++;
				ans%=998244353;
			}
	cout<<ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	t=1;
	while(t--)
		solve();
	return 0;
}
