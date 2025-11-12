#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
vector<char> ans;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	string s;
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if(s[i] - '0' <= 9){
			ans.push_back(s[i]);
		}
	}
	sort(ans.begin(),ans.end());
	for(int i = ans.size()-1;i >= 0;i--){
		cout << ans[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
