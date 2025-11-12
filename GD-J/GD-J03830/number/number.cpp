#include <iostream>
#include<string>
#include<algorithm> 
#include<vector>
#include<queue>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int>num;
	int cnt=0;
	for(int i=0;i<s.length();i++){
		if('0'<=s[i]&&s[i] <= '9'){
			int _tmp = s[i] - '0';
			num.push_back(_tmp);
			cnt++;
		}
	}
	sort(num.rbegin(), num.rend());
	string ans = "";
	for (int i=0;i<cnt;i++){
		ans.push_back((char)(num[i]+'0'));
	}
	cout<<ans;
	return 0;
}
