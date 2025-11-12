#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
signed main(){
//	freopen("xor6.in","r",stdin);
//	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin >> n >> k;
	a[0]=0;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		a[i]^=a[i-1];
	}
	int ans=0;
	for(int t = 1;t<=n;t++){
		int i=t,j=t;
		int anse = 0;
		while(i<=n&&j<=n){
			if((a[j]^a[i-1])!=k) ++j;
			else{
				++j;
				i=j;
				anse++;
			}
		}
		if(j>n&&i<=n) while(i<=n){
			if((a[j-1]^a[i-1])==k){
				anse++;
				break;
			}
			i++;
		}
		ans=max(ans,anse);
	}
	cout << ans;
	return 0;
}