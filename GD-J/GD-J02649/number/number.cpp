#include<bits/stdc++.h>
using namespace std;
string s;
vector<char>t;
bool cmp(char a, char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9')t.push_back(s[i]);
	}
	sort(t.begin(), t.end(),cmp);
	for(auto x:t)cout<<x;
	return 0;
}
