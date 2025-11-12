#include <bits/stdc++.h>
using namespace std;
map<string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out", "w", stdout); 
	int n, q;
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		string a, b;
		cin >> a >> b;
		mp[a]=b;
		mp[b]=a;
	}
	while(q--){
		string x, y;
		string tmp = x;
		cin >> x >> y;
		int cnt = 0;
		for(int i = 0;i <= n;i++){
			for(int len = 1;i + len - 1 <= n;len++){
				if(mp.count(x.substr(i, len))){
					tmp = x;
					for(int j = 0;j < len;j++){
						tmp[i+j] = mp[x.substr(i, len)][j];
					} 
					if(tmp == y) cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
}
/*
abce
abcd
*/
