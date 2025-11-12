#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	vector<int>vec;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9')vec.push_back(s[i]-'0');
	}
	sort(vec.begin(),vec.end(),cmp);
	if(vec[0]==0){
		cout<<0;
		return 0;
	}
	for(int t:vec){
		cout<<t;
	}
	return 0;
}
