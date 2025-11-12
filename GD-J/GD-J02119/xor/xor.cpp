#include <bits/stdc++.h>
using namespace std;
int n,k,ans,a[8888888];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++){
		int p=a[i];
		if (p==k){
			ans++;
			continue;
		}
		for (int j=i+1;j<=n;j++){
			p^=a[j];
			if (p==k){
				ans++;
				i=j;
				break;
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
