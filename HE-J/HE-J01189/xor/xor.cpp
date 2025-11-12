#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[550000],ans,ma;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int now=a[i];
		ans=0;
		for(int j=i;j<=n;j++){
			if(now==k){
				ans++;
				now=a[j+1];
				continue;
			}
			now^=a[j+1];
		}
		ma=max(ma,ans);
	}
	cout<<ma;
	return 0;
}
