#include <bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][2],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> s[i][0] >> s[i][1];
	}
	while(q--){
		cin >> t1 >> t2;
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			if(t1.find(s[i][0]) != -1 && t1.find(s[i][1])!= -1)cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}
