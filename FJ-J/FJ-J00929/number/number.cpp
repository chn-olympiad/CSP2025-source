#include<bits/stdc++.h>
using namespace std;
long long num[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(num[i]){
			num[i]--;
			cout<<i;
		}
	}
	return 0;
}