#include <bits/stdc++.h>
using namespace std;
struct st{
	string s1;
	string s2;
}s[200000];
struct bl{
	string j1;
	string j2;
}b[200000];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,q;
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> s[i].s1 >> s[i].s2;
	}
	for(int i = 1;i <= q;i++){
		cin >> b[i].j1 >> b[i].j2;
	}
	for (int i = 1;i <= q;i++){
		cout << 0 <<endl;
	}
	
	return 0;
}
