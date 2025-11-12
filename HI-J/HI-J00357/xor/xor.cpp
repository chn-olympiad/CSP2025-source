#include <bits/stdc++.h>
using namespace std;
int a[500005],pos;
int main(){
	freopen("xor.in","w",stdin);
	freopen("xor.in","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	int ans=0;
	for (int i = 1;i <= n;i++){
		for (int j = i;j <= n;j++){
			int l = a[i];
			for (int k = i+1;k <= j;k++){
				l = (l ^ a[k]);
			}
			if (l == m){
				ans++;
				i = j;
			}
		}
	}
	cout << ans;
	return 0;
}
