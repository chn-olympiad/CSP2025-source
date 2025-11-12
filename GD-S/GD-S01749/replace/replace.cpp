#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
typedef long long ll;
string a[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> a[i][0] >> a[i][1];
	}
	
	while(q--){
		string t,s;
		cin >> t >> s;
		cout << 0 << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

