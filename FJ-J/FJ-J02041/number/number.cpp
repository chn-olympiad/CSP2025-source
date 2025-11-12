#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	
	vector<int>xl(s.size());
	int tt=0;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
		xl[tt]=int(s[i]);
		tt++;	
		}
	}
	sort(xl.begin(),xl.end());
	for(int i=s.size()-1;i>=s.size()-tt;i--){
			cout<<char(xl[i]);
	}

	
	return 0;
}
