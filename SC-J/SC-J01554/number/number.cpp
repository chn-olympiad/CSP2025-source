#include<bits/stdc++.h>
using namespace std;
long long num[10];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(num[i]>0){
			num[i]--;
			cout<<i;
		}
	}
	return 0;
} 