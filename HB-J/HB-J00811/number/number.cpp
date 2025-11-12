#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> num;
bool cmp(int a, int b){
	return a>b;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin>>s;
	for(int i=0; i<(int)s.size(); i++){
		if(isdigit(s[i])){
			num.push_back(int(s[i]-'0'));
		}
	}
	sort(num.begin(), num.end(), cmp);
	for(auto it: num){
		cout<<it;
	}	
	return 0;

}
