#include <bits/stdc++.h>
using namespace std;
pair<string,string> a[200100];
int s[255];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n;
	cin >> n;
	for (int i=1;i<=n;i++)cin >> a[i].first >> a[i].second;
	int q;
	cin >> q;
	while (q--){
		string t1,t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size())cout << 0;
		else cout << t1.size()-2;
	} 
	return 0;
}
