#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;

void mymain(){
	string s;
	vector<int> a;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			int b = s[i] - '0';
			a.push_back(b);
		}
	}
	sort(a.begin(), a.end());
	for(int i = a.size() - 1; i >= 0; i--) cout << a[i];
	
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
//	int n;
//	cin >> n;
//	while(n--){
		mymain();
//	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//#Shang4Shan3Ruo6Shui4
