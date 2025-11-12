#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int> cnt(s.length(),-1);
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			cnt[i] = s[i]-'0';
		}
	}
	sort(cnt.begin(),cnt.end(),greater<int>());
	for(int i=0;i<s.length();i++){
		if(cnt[i]==-1) break;
		cout<<cnt[i];
	}
	return 0;
}
