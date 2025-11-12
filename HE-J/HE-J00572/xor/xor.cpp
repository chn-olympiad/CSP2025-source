#include<bits/stdc++.h>
using namespace std;
int n,last=1;
long long k,ans,l[500010];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i=1;i<=n;i++){
	cin >> l[i];
	}
	for (int i=1;i<=n;i++){
	long long cnt;
	for (int j=i;j>=last;j--){
	cnt^=l[j];
	if (cnt==k){
	last=i+1;
	ans++;
	break;
	}
	}
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
