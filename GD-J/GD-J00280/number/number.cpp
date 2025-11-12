#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int s_len=s.length();
	vector<int>number;
	for(int i=0;i<s_len;i++){
		if(s[i]>'0' && s[i]<'9'){
			number.push_back(s[i]-'0');
		}
	}
	sort(number.begin(),number.end(),cmp);
	for(int i=0;i<s_len;i++){
		cout<<number[i];
	}
	return 0;
}
