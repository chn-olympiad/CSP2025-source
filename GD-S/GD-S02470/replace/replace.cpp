#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 20;
int n,q;
string s[N],t[N];
string a,b,tmp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++) cin >> s[i] >> t[i];
	if(q <= 300){
		while(q--){
		cin >> a >> b;
		int len = a.size();
		long long ans = 0ll;
		for(int i = 0;i < len;i++){
			for(int j = 1;j <= n;j++){
				int len2 = s[j].size();
				tmp = "";
				for(int k = i;k <= i + len2 - 1;k++){
					tmp += a[k];
				}
				//cout << i << " " << j << " " << tmp << '\n';
				if(tmp == s[j]){
					string tmp2 = a;
					for(int k = i;k <= i + len2 - 1;k++){
						tmp2[k] = t[j][k - i];
					}
					//cout << tmp2 << " " << b << '\n';
					if(tmp2 == b){
						ans++;
					}
				}
			}
		}
		cout << ans << '\n';
	}	
	}else{
		while(q--){
			cout << 0 << '\n';
		}
	}
	return 0;
}
