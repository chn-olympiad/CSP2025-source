#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin >> s;
	int n = s.length();
	vector<int> vec; 
	for(int i = 0;i < n;i++){
		if(s[i] >= '0' && s[i] <= '9')
			vec.push_back(s[i] - '0'); 
	}
	sort(vec.begin(),vec.end(),greater<int>());
	for(int i = 0;i < (int)vec.size();i++)
		cout << vec[i];
	cout << "\n"; 
	return 0;
}
