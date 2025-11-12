#include <bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;

int n,q;
string s[N][5];
string t[N][5];
int ans;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 	freopen("replace.in","r",stdin);
 	freopen("replace.out","w",stdout);
 	cin >> n >> q;
 	for (int i=1;i<=n;++i) cin >> s[i][1] >> s[i][2]; 
	for (int i=1;i<=q;++i) cin >> t[i][1] >> t[i][2]; 
	
	for (int i=1;i<=q;++i){
		ans = 0;
		if (t[i][1].length() != t[i][2].length()){
	 		cout << "0\n";
	 		continue;
		}
		int x=0,y=t[i][1].length()-1;
		while (t[i][1][x] == t[i][2][x]) x++;
		while (t[i][1][y] == t[i][2][y]) y--;
		
		
		for (int j=1;j<=n;++j){
			string st = t[i][1];
			int id = st.find(s[j][1]);
			
			bool is = false;
			while (id >= 0 && id < st.length() && !is){
				is = true;
				int len = s[j][1].length();
				st = st.substr(id+1,st.length()-id+1);
				if (id > x || id+len-1 < y){
					id = st.find(s[j][1]);
					is = false;
					continue;
				}
			
				for (int z=0;z<len;++z){
					if (s[j][2][z] != t[i][2][z+id]){
						is = false;
						break;
					}
				}
				if (is) ans++;
				
				id = st.find(s[j][1]);
			}
			
		}
		cout << ans << '\n';
	}
	
	
	
	
 	
 	return 0;
 }
