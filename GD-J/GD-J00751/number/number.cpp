#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
long long num[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	string s;
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[s[i]-'0']++;
		}
	}
	for(long long i=9;i>=0;i--){
		for(long long j=0;j<num[i];j++){
			cout<<i;
		}
	}
} 
