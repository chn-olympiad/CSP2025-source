#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll

int n,k,ans;
const int N=5e5+10;
int a[N];
int sum;

void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=a[i-1];
	}
	for(int i=1;i<=n;i++)
		for(int j=2;j<=n;j++)
			if((a[j]-a[i])%k==0){
				i=j;
				ans++;
				continue;
			}
	cout<<ans;
}

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	t=1;
	while(t--)
		solve();
	return 0;
}
