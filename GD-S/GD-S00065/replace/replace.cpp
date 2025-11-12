#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	vector<vector<int>> s(n,vector<int> (2)),t(n,vector<int> (2));
	for(int i=0;i<n;++i){
		cin >> s[i][0] >> s[i][1];
	}
	for(int i=0;i<q;++i){
		cin >> t[i][0] >> t[i][1];
	}
	cout << n;
	return 0;
}
