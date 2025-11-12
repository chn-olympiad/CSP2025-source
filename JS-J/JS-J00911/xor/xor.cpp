#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int ans;
void solve(){
	int cnt = 0;
	for(int i = 1;i<=n;i++){
		if(a[i] == 1) cnt++;
	}
	cout<<cnt;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	if(k == 0){
		cout<<n/2;
		return 0;
	}else if(k == 1){
		solve();
		return 0;
	}else{
		for(int i = 1;i<=n;i++){
			if(a[i] == k){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
