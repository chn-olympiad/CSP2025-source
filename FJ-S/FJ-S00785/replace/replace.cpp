#include <bits/stdc++.h> 
using namespace std;

const int N = 2e5 + 10;
int n, q, ans;
pair<string, string> arr[N];
string s1, s2;

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q; 
	for(int i = 0;i < n;i++){
		cin >> arr[i].first >> arr[i].second;
	}
	for(int i = 0;i < q;i++){
		ans = 0;
		cin >> s1 >> s2;
		for(int i = 0;i < n;i++){
			if(s1.find(arr[i].first) != s1.find("!")){
				string a, b, c;
				a = s1.substr(0, s1.find(arr[i].first));
				b = arr[i].second;
				c = s1.substr(s1.find(arr[i].first) + arr[i].first.size());
				if(s2 == (a + b + c)) ans++;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
