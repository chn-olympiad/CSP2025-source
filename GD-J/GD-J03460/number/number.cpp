#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(number1,"d");
	fclose(number1,"s");
	string s;
	long long a[10]={0};
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			cout<<i;
		}
	}
	return 0;
}
