#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
vector<int> num;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= '0' and s[i] <= '9'){
			num.push_back(s[i] - '0');
		}
	}
	sort(num.begin(),num.end());
	reverse(num.begin(),num.end());
	for(int i = 0; i < num.size(); i++){
		printf("%d",num[i]);
	}
	return 0;
}
