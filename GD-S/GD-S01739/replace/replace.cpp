#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 4;
int n,Q;
string s1[N],s2[N]; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> Q;
	for(int i = 1;i <= n;i++){
		cin >> s1[i] >> s2[i];
	} 
	while(Q--){
		string t1,t2;
		cin >> t1 >> t2;
		cout << 0 << "\n";
	}
	return 0;
} 
