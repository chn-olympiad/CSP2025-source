#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	vector<char> str;
	cin>>s;
	for(char c:s){
		if(c>='0'&&c<='9'){
			str.push_back(c);
		}
	}
	sort(str.begin(),str.end(),[](char a,char b)->bool{
		return int(a)>int(b);
	});
	for(char c:str){
		cout<<c;
	}
	return 0;
} 
