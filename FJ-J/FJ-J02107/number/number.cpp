#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	vector<int> num;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num.push_back(s[i]-'0');
		}
	}
	sort(num.begin(),num.end());
	int ans=0;
	for(int i=num.size()-1;i>=0;i--){
		ans=ans*10+num[i];
	}
	cout<<ans;
	return 0;
}

