#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
int n, q;
string s1[N], s2[N], t1, t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i ++){
		cin >> s1[i];
		cin >> s2[i];
	}
	while(q --){
		int ans = 0;
		cin >> t1;
		cin >> t2;
		for(int i = 1;i <= n;i ++){
			if(s1[i].size() > t1.size() || s2[i].size() > t2.size()){
				continue;
			}
			for(int i1 = 0;i1 < t1.size();i1 ++){
				bool flag = true;
				for(int j = 1;j <= s1[i].size();j ++){
					if(s1[i][j-1] != t1[i1+j]){
						flag = false;
						break;
					}
				}
				if(!flag)continue;
				for(int i2 = 0;i2 < t2.size();i2 ++){
					bool flag = true;
					for(int j = 1;j <= s1[i].size();j ++){
						if(s1[i][j-1] != t1[i2+j]){
							flag = false;
							break;
						}
					}
					if(!flag)continue;
					for(int ii = 0;ii < t1.size();ii ++){
						char ss1, ss2;
						if(i1 <= ii && ii <= i1 + s1[i].size() - 1){
							ss1 = s2[i][ii-i1];
						}else {
							ss1 = t1[ii];
						}
						if(i2 <= ii && ii <= i2 + s1[i].size() - 1){
							ss2 = s2[i][ii-i1];
						}else {
							ss2 = t1[ii];
						}
						if(ss1 != ss2){
							flag = false;
							break;
						}
					}
					if(flag) ans ++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}