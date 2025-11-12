#include<bits/stdc++.h>
using namespace std;

string s;
int n;
vector<int> ans;

bool cmp(int x,int y){
	return x > y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	n = s.size();
	for(int i = 0;i < n;i++){
		if(isdigit(s[i])){
			ans.push_back(s[i] - '0');
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	if(ans[0] == 0) return cout << 0,0;
	else{
		for(int i : ans){
			cout << i;
		}
	}
	return 0;
}