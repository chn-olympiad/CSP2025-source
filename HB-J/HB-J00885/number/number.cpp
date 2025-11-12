#include <bits/stdc++.h>
using namespace std;
string s,nums;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<(int)(s.size());i++){
		if(s[i]>='0' && s[i]<='9'){
			nums+=s[i];
		}
	}
	sort(nums.begin(),nums.end(),greater<>());
	cout << nums;
	return 0;
}
