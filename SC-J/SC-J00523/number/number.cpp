#include<bits/stdc++.h>
using namespace std;
const int Max=1e6+5;
void solove(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
}
vector <int> d;
int main(){
	solove();
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0')	d.push_back(int(s[i]-'0'));
	}
	sort(d.begin(),d.end());
	for(int i=d.size()-1;i>=0;i--){
		cout<<d[i];
	}
	return 0;
}