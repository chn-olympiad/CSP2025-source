#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	long long h[10]={0};
	string s;
	cin>>s;
	for(long long i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			h[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(long long j=0;j<h[i];j++){
			std::cout<<i;
		}
	}
	return 0;
} 