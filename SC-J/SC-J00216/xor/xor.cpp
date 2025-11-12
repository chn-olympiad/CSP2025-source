#include<bits/stdc++.h>
using namespace std;
long long a[500010],pos,cnt;
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		if(((a[i]^0)==k) || ((pos^a[i])==k)){
			pos = 0;
			cnt++;
		}
		else pos = pos^a[i];
	}
	cout << cnt;
	return 0;
}