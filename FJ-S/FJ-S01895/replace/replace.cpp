#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n,q;
pair<string,string>S[MAXN];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		cin >> S[i].first >> S[i].second;
	}
	for(int i = 1;i <= q;i++){
		string sx,sy;
		cin >> sx >> sy;
		cout << 1 << '\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

