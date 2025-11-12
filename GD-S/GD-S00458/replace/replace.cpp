#include<bits/stdc++.h>
using namespace std;
int n , q;
string s[5005][3];
string f[5005] , g[5005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1 ; i <= n ;i++){
		cin >> s[i][0] >> s[i][1];
	}
	int ans = 0;
	while(q--){
		ans = 0;
		string s1 , s2;
		
		cin >> s1 >> s2;
		f[0] = s1[0];
		for(int i = 1 ; i < s1.size() ; i++){
			f[i] = f[i - 1] + s1[i];
		}
		for(int i = s1.size() - 1 ; i >= 0 ; i--){
			g[i] = s1[i] + g[i +1];
		}
		for(int i = 0 ; i < s1.size() ; i++){
			for(int j = 1 ; j <= n ; j++){	
				if(s1[i] == s[j][0][0]){
					string s3 = "";
					if(i != 0){
						s3 += f[i - 1];
					}
					s3 += s[j][1];
					s3 += g[i + s[j][1].size()];
					if(s3 == s2){
						ans++;
					}
				}
			}
			
		}
		cout << ans << endl;
	}
}
