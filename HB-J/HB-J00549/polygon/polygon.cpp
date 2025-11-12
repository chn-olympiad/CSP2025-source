#include <bits/stdc++.h>
using namespace std;
int n,m,sum,maxn,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	if(n==3){
		for(int i=1;i<=n;i++){
			maxn = max(maxn,a[i]);
			sum += a[i];
		}
		if(sum>maxn*2) cout << 1;
		else cout << 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
