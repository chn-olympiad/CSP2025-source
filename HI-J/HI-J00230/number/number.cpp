#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

long long ans=0;
string s;
vector<int> v;

bool cmp(int a, int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	for(int i=0; i<s.size(); i++){
		if(s[i]>=48 and s[i]<=57) v.push_back(s[i]-'0');
	}
	sort(v.begin(), v.begin()+v.size(), cmp);
	
	while(not v.empty()){
		cout << v[0];
		v.erase(v.begin()+0);
	}
	
	
	return 0;
}

