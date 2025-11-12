#include<bits/stdc++.h>
using namespace std;
bool cmp(string a,string b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,a[100001];
	int t = 0;
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if(s[i] >='0' && s[i] <= '9'){
			a[t] = s[i];
			t++;
		}
	}
	sort(a,a+t,cmp);
	string ans;
	for(int i= 0;i < t;i++){
		ans+=a[i];
	}
	cout << stoi(ans);
	return 0;
}
