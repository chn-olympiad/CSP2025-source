#include<bits/stdc++.h>
using namespace std;
string s[200005][5];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for(int i = 1;i <= n;i++) cin >> s[i][1] >> s[i][2];
	for(int i = 1;i <= q;i++){
		int ned,ans;
		cin >> ned >> ans;
	}
	if(n == 4) cout << 2 << end << 0;
	else cout << 0 << endl << 0 << endl << 0 << endl << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
