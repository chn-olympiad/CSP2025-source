#include<bits/stdc++.h>

using namespace std;
string s;
long long num[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[s[i]-'0']++;
		}
	}
	string ans="";
	for(int i=9;i>=0;i--){
		while(num[i]>0){
			num[i]--;
			ans+='0'+i;
		}
	}
	cout<<ans;
	return 0;
}

