#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int> a(10,0);
	for(int i=0;i<s.length();i++){
//		cout<<(s[i]-'0')<<endl;
		if((s[i]-'0')<=9 && (s[i]-'0')>=0) a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			cout<<i;
		}
	}
	return 0;
}
