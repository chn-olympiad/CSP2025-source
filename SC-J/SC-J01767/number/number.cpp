#include<bits/stdc++.h>
#include<map>
using namespace std;
vector<int>value(100,0);
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			value[s[i]-'0']++;
		}
	}
	string t="";
	for(int i=9;i>=0;i--){
		for(int j=1;j<=value[i];j++)	t+=(i+'0');
	}
	cout<<t;
	return 0;
}