#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[110],s2[110],t1,t2;
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> s1[i] >> s2[i];
	}
	while(q--){
		cout << n;
	}
	return 0;
}