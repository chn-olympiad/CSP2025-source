#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 50;
int n,k;
int a[N];
bool f = 0,vis[N];
int ans;

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(a[i] != 1) f = 1;
	}
	if(!f){
		if(k == 1){
			cout<<n;
			return 0;
		}else if(k == 0){
			cout<<n / 2;
			return 0;
		}
	}
	
	for(int l = 1;l <= n;l++){
		int r = l;
		while(l <= r && r <= n && a[l] >= 0){
			int s = a[l];
			for(int i = l + 1;i <= r;i++){
				s ^= a[i];
			}
			if(s == k){
				ans++;
				a[l] = -100;
				for(int i = l + 1;i <= r;i++){
					a[i] = -100;
				}
			}
			r++;
		}
	}
	
	cout<<ans;
	return 0;
}
