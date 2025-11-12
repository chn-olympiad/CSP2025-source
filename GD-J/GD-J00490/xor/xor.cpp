#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n, k, a[N], sum[N], xo[1005][1005], ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(xo,-1,sizeof(xo));
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			xo[i][j]=sum[j]^sum[i-1];
		}
	}
	int tmp=1;
	for(int j=1;j<=n;j++){
		for(int i=tmp;i<=n;i++){
			if(xo[i][j]==k){
				ans++;
				tmp=j+1;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
