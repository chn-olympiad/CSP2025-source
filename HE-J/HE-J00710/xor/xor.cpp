#include <iostream>
using namespace std;
int n,k,a[500005],p,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	if (k != 1||k!=0){
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1;i<=n;i++){
		cin >> a[i];
		if (k == 1){
			if (a[i] == 1){
				p = 0;
				ans++;
			}else{
				p++;
				if (p == 2){
					p = 0;
					ans++;
				}
			}
		}else{
			if (a[i] == 0){
				p = 0;
				ans++;
			}else{
				p++;
				if (p == 2){
					p = 0;
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
