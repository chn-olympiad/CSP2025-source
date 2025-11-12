#include<bits/stdc++.h>
#include<cstdio>

using namespace std;

bool cmp(int a,int b){
	return a > b;
}

int main(){
	bool flg = true;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	vector<int> ve;
	string s;
	cin >> s;
	int i = s.length();
	while(i--){
		char k = s[i];
		if('0' <= k && k <= '9'){
			ve.push_back(k - '0');
			if(k != '0'){
				flg = false;
			}
		}
	}
	sort(ve.begin(),ve.end(),cmp);
	if(flg){
		cout << 0;
		return 0;
	}
	for(int i = 0;i < ve.size();i++){
		cout << ve[i];
	}
}
