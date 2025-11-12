#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	vector<int> num;
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			num.push_back(s[i] - '0');
			//cout << s[i] - '0' << endl;
		}
	}
	if(num.size() == 1){
		cout << num[0] << endl;
		return 0;
	}
	sort(num.begin(),num.end(),cmp);
	for(int i = 0;i < num.size();i++){
		cout << num[i];
	}
	cout << endl;
}
