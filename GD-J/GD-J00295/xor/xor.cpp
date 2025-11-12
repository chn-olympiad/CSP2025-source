#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n,m,a[N],sum[N],res;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int sum = a[i];
			for(int k=i+1;k<=j;k++){
				sum ^= a[k];
			}
			if(sum == m){
				i = j;
				res++;
				break;
			}
		}
	}
	cout << res;
	return 0;
}
