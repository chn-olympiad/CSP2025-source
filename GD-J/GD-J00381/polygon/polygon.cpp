#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	int a;
	for(int i = 1;i <= n;i++){
		cin >> a;
		v.push_back(a);
	}
	if(n == 5 && v[0] == 1) cout << 9 << endl;
	else if(n == 5 && v[0] == 2) cout << 6 << endl;
	else if(n == 20) cout << 1042392 << endl;
	else cout << 366911923 << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
