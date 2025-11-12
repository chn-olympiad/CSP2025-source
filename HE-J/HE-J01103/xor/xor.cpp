#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],ans; 
bool f[500005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=1;i<=n;i++){
		int zt;
		for(int j=i;j<=n;j++){
			zt=a[i];
			for(int k=i+1;k<=j;k++)zt^=a[k];
			if(zt==k){
				int op=0;
				for(int k=i;k<=j;k++){
					if(f[k]){
						op=1;break;
					}
				}
				if(op==0){
					for(int k=i;k<=j;k++){
						f[k]=1;
					}ans++;				
				}
			}
		}
	}cout << ans;
	return 0;
} 
