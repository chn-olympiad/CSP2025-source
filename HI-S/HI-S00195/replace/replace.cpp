#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,q;
	cin >> n >> q;
	for (int i = 1;i <= n;i++){
		string s1[200010],s2[200010];
		cin >> s1[i] >> s2[i];
	}
	for (int i = 1;i <= q;i++){
		string t1[200010],t2[200010];
		cin >> t1[i] >> t2[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
