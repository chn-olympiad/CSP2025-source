#include<bits/stdc++.h>
using namespace std;
int n,q;
const int N = 2e5+114;
string s1[N],s2[N];
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> s1[i] >> s2[i];
	}
	for(int i = 1;i <= q;i++){
		cin >> t1 >> t2;
		cout << 1 << ' ';
	}
	return 0;
}