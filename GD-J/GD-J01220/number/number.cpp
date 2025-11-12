#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string str;
	vector<int> vec;
	cin>>str;
	for(int i=0;i<str.length();i++){
		if(str[i]>='0'&&str[i]<='9'){
			vec.push_back(str[i]-48);
		}
	}
	sort(vec.begin(),vec.end(),greater<int>());
	for(auto v:vec){
		cout<<v;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
