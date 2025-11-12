#include<bits/stdc++.h>
using namespace std;

long long num[10];
string s;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		int x=s[i]-'0';
		if(x>=0&&x<=9){
			num[x]++;
		}
	}
	string s1;
	for(int i=9;i>=0;i--){
		while(num[i]){
			char a=(char)(i+'0');
			cout<<a;
			num[i]--;
		}
	}
	
	
	return 0;
}