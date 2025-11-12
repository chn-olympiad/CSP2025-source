#include<bits/stdc++.h>
using namespace std;

string s;
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	int len = s.size();
	vector<int> a;
	for(int i = 0; i < len; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			int x = s[i] - '0';
			a.push_back(x);
		}
	}
	sort(a.begin(), a.end(), cmp);
	for(auto i : a){
		cout << i;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
