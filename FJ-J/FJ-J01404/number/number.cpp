#include <bits/stdc++.h>
using namespace std;
vector<int> vec;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char c;
	while(cin >>c){
		if(isdigit(c)){
			vec.push_back(c-'0');
		}
	}
	sort(vec.begin(),vec.end());
	reverse(vec.begin(),vec.end());
	for(auto t:vec){
		cout << t;
	}
	cout <<endl;
	return 0;
} 
