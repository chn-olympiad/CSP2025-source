#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 2e5+3;
int n,k,a[N],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	bool flag = 0,book = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] != 1) flag = 1;
		if(a[i] != 1 && a[i] != 0) book = 1;
	} 
	if(!flag){
		cout << n/2;
		return 0;
	} 
	if(!book){
		if(k == 0){
			ans = 0;
			int i = 1;
			while(i <= n){
				if(!a[i]) ans++,i++;
				if(a[i] == 1){
					int tmp = 0;
					for(int j = i;j <= n;j++){
						if(!a[j]) break;
						tmp++;
					}
					ans += tmp/2;
					i += tmp;
				}
			}
		cout << ans << '\n';
		return 0;
		}else if(k == 1){
			ans = 0;
			for(int i = 1;i <= n;i++) if(a[i] == 1) ans++;
			cout << ans << '\n';
			return 0;
		}
	}
	return 0;
}