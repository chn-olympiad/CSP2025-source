//2025 CSP-J t1 number.cpp  by ACGO - Dark_eve
#include<bits/stdc++.h>
using namespace std;

string s,ans = "";
vector<char>a;

bool cmp(int a,int b){ 
	return a > b;
}

int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a.push_back(s[i]);
		}
	}
	
	sort(a.begin(),a.end(),cmp);
	
	for(int i = 0;i < a.size();i++){
		ans += a[i];
	}
	
	cout << ans;
	
	return 0;
}

