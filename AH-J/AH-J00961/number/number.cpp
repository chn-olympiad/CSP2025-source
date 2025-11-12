#include <bits/stdc++.h>
using namespace std;
int number[10],i;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int a=s.size();
	for(int i=0;i<a;i++){
		if(isdigit(s[i])){
			number[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<number[i];j++){
			cout<<i;
		}
	}
	return 0;
}
