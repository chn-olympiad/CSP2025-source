#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s="";
	cin>>s;
	vector<int> numbers;
	for(int i=0;i<s.length();i++){
		if('0'<=s[i] and s[i]<='9'){
			numbers.push_back(s[i]-'0');
		}
	}
	sort(numbers.begin(),numbers.end(),cmp);
	for(int i=0;i<numbers.size();i++){
		cout<<numbers[i];
	}
} 
