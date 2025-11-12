#include <bits/stdc++.h>
#define IOS std::ios::sync_with_stdio(false),std::cin.tie(nullptr),std::cout.tie(nullptr)
#define N 1003

int n,q;
std::string s[N][2];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	IOS;
	std::cin >> n >> q;
	for(int i = 1;i <= n;i++){
		std::cin >> s[i][0] >> s[i][1];
	}
	while(q--){
		std::string t1,t2;
		int ans = 0;
		std::cin >> t1 >> t2;
		for(int i = 0;i < t1.size();i++){
			for(int j = 1;j <= n;j++){
				bool f = true;
				for(int k = 0;k < s[j][0].size();k++){
					if(t1[i + k] != s[j][0][k]){
						f = false;
						break;
					}
				}
				if(f){
					bool f2 = true;
					std::string tmp;
					for(int k = 0;k < i;k++){
						tmp += t1[k];
					}
					for(int k = 0;k < s[j][0].size();k++){
						tmp += s[j][1][k];
					}
					for(int k = s[j][0].size() + i;k < t1.size();k++){
						tmp += t1[k];
					}
					for(int k = 0;k < t1.size();k++){
						if(tmp[k] != t2[k]){
							f2 = false;
							break;
						}
					}
					if(f2){
						ans++;
					}
				}
			}
		}
		std::cout << ans << '\n';
	}
	return 0;
}

