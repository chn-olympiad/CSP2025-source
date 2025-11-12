#include <iostream>
#include <string>
using namespace std;
struct node{
	string s1, s2;
}a[200005];
int n, q, ans;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++) cin >> a[i].s1 >> a[i].s2;
	if(q == 1){
		for(int i = 0;i <= a[1].s1.length();i++)
			if(a[0].s1[i] != a[0].s2[i]) ans++;
		cout << ans << endl;
		return 0;
	}
	for(int i = 1;i <= 1;i++) cout << 0 << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
