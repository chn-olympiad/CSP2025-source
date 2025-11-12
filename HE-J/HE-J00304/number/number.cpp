#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
typedef long long LL;
typedef pair<int, int> PII;

string s;
vector<int> v;

int main(){
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin>>s;
	int n = s.size();
	s = ' ' + s;
	
	for(int i = 1 ; i <= n ; i ++){
		if(s[i] >= '0' && s[i] <= '9'){
			v.push_back(s[i] - '0');
		}
	}
	
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	
	int l = v.size();
	for(int i = 0 ; i < l ; i ++){
		cout<<v[i];
	}
	
	return 0;
} 
