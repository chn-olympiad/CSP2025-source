#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5+10;
ll n,k;
ll a[maxn];
bool vis[maxn],flag;
ll ans = 0;
bool check(ll x,ll y){
	ll add_i_to_j = 0;
	for(int i = x;i<=y;++i){
		add_i_to_j^=a[i];
		if(add_i_to_j>k){
			return false;
		}
		if(add_i_to_j == k){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;++i){
		cin>>a[i];
	}
	if(k == 0){
		for(int i =1;i<=n;++i){
			if(a[i]!=1){
				flag = true;
				break;
			}
		}
		if(!flag){
			cout<<n/2;
		}
		else{
			for(int i = 1;i<=n;++i){
				if(vis[i]) continue;
				int l = i-1,r = i+1;
				if(a[i] == 1){
					if(a[l] == 1&&l>=1&&!vis[l]){
						ans++;
						vis[i] = true;
						vis[l] = true;
			//		cout<<ans<<":"<<i<<":"<<i-1<<endl;
					}
					else if(a[r] == 1&&r<=n&&!vis[r]){
						ans++;
						vis[i] = true;
						vis[r] = true;
			//		cout<<ans<<":"<<i<<":"<<i+1<<endl;
					}
				
				}
				else if(a[i] == 0){
						ans++;
						vis[i] = true;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	
	else if(k==1){
		
		for(int i = 1;i<=n;++i){
			if(vis[i]) continue;
			int l = i-1,r = i+1;
			if(a[i] == 1){
				if(a[l] == 0&&l>=1&&!vis[l]){
					ans++;
					vis[i] = true;
					vis[l] = true;
//					cout<<ans<<":"<<i<<":"<<i-1<<endl;
				}
				else if(a[r] == 0&&r<=n&&!vis[r]){
					ans++;
					vis[i] = true;
					vis[r] = true;
//					cout<<ans<<":"<<i<<":"<<i+1<<endl;
				}
				else{
					vis[i] = true;
					ans++;
				}
			}
		}
	}
	else{
		ll last_end = 1;
		for(int i = last_end;i<=n;++i){
			for(int j = i+1;j<=n;++j){
				if(check(i,j)){
					ans++;
					last_end = j+1;
//						cout<<i<<"->"<<j<<endl;
					break;
				
				}
			}
		}
	}
	cout<<ans;

	return 0;
}