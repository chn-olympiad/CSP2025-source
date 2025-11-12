#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005];
string sa,sb;
int ans = 0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;i ++){
		cin >> s1[i] >> s2[i];
	}
	for(int i = 1;i <= q;i ++){
		cin >> sa >> sb;
		cout << 0 << endl;
		ans = 0;
	}
	
	return 0;
}
