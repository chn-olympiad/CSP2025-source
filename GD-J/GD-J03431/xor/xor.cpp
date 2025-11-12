#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
long long ans;
int a[N];
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		for(int j = i; k <= n; j++){
			int cnt= a[i];
			for(int l = i; l <= j; l++){
				cnt += !(cnt|a[l]);
				if(cnt == k) ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
//¸ø5·ÖßÂ£¬ÇòÇòÁË 
