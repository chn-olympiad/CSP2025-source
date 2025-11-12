#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
string s;
vector<int> v;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char c:s){
		if(c>='0'&&c<='9') v.push_back(c-'0');
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	for(int i:v) printf("%d",i);
	return 0;
} 
