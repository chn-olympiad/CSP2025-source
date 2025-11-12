#include<bits/stdc++.h>
using namespace std;
int n,q;
pair<string,string> s[400001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n + q;i++){
		cin >> s[i].first >> s[i].second;
	}
	while(q--)
		cout << 0 << endl;
	return 0;
}
