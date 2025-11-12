#include<bits/stdc++.h>
using namespace std;

string s;
vector<char >vec;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9')vec.push_back(s[i]);
	}
	sort(vec.begin(),vec.end());
	bool tf=0;
	for(int i=vec.size()-1;i>=0;i--){
		if(vec[i]!='0')tf=1;
		if(tf==1)cout<<vec[i];
	}
	if(tf==0)cout<<0;
	return 0;
} 