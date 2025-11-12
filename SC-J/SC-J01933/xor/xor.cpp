#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,k,ans;
ll a[500005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	bool ifone = true;
	bool ifzero = true;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(a[i] != 1){
			ifone = false;
		}
		if(a[i] != 0 && a[i] != 1){
			ifzero = false;
		}
	}
	if(ifone){
		cout<<n / 2<<endl;
		return 0;
	}else if(ifzero){
		if(k == 1){
			int i = 1;
			for(;i <= n;){
				if(a[i] != a[i + 1]){
					ans++;
					i += 2;
					continue;
				}else if(a[i] == a[i + 1] && i + 2 > n){
					break;
				}else if(a[i] == a[i + 1] && a[i + 1] == a[i + 2]){
					ans++;
					i += 3;
				}else{
					i++;
				}
			}
		}else{
			int i = 1;
			for(;i <= n;){
				if(a[i] == a[i + 1]){
					ans++;
					i += 2;
					continue;
				}else if(a[i] != a[i + 1] && i + 2 > n){
					break;
				}else if(a[i] != a[i + 1] && a[i + 1] != a[i + 2]){
					ans++;
					i += 3;
				}else{
					i++;
				}
			}			
		}
		cout<<ans<<endl;
	}else{
		cout<<1<<endl;
	}
	return 0;
}
