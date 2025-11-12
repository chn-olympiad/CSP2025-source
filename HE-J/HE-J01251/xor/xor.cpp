#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
bool f[N];
int ans;
/*//十进制转二进制 
string wei(int a){
	string s;
	while(a){
		s = char(a % 2 + '0') + s;
		a /= 2;
	}
	return s;
}
*/
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool flag = true;
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(i > 1 && a[i] != a[i-1]) flag = false;
	}
	if(flag == true){
		if(a[1] == k){
			cout << n;
			return 0; 
		}else{
			cout << 0;
			return 0;
		}
	}
	for(int i = 1; i <= n; i++){
		int cnt = 0;
		if(a[i] == k){
			ans++;
			f[i] = false;
			continue;
		}
		for(int j = i; j <= n; j++){
			if(cnt == k && f[i] && f[j]){
				ans++;
				for(int k = i; k <= j; k++) f[k] = false; 
				break;
			}
			else if(a[i] == a[j]){
				continue;
			}
			else if(a[i] == 0 || a[j] == 0){
				cnt += max(a[i], a[j]);
			}
		}
	}
	cout << ans;
	return 0;
}
