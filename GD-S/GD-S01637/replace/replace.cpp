#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
string s[N][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,q;
	cin >> n >> q;
	for(int i = 1;i <= n;i++)cin >> s[i][1] >> s[i][2];
	while(q--){
		string x,y;
		cin >> x >> y;
		long long ans = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 0;j < s[i][1].size();j++){
				string lng = x;
				bool flag = true;
				for(int k = j;k < s[i][1].size();k++){
					if(lng[k]!=s[i][1][k]){
						flag = false;
						break;
					}
					lng[k] = s[i][2][k];
				}
				if(flag&&lng==y)ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
