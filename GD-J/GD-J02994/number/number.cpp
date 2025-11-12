#include<bits/stdc++.h>
using namespace std;
string s;
vector<int>a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a.push_back(int(s[i]-'0'));
		}
	}
	sort(a.begin(),a.end());
	int bj=0;
	for(int i=a.size()-1;i>=0;i--){
		if(bj==0&&a[i]==0)continue;
		bj=1;
		cout<<a[i];
	}
	if(bj==0)cout<<0;
	return 0;
} 
