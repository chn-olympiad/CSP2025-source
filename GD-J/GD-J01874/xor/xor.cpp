#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>k;
	vector<long long> a(n);
	for(int i = 0;i < n;i++)cin>>a[i];
	if(k == 0) cout<<1;
	if(k == 1){
		long long cnt = 0;
		for(int i = 0;i < n;i++){
			if(a[i] == 1) cnt++;
		}
		cout<<cnt;
	}
	return 0;
}
