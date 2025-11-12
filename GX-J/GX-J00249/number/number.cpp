#include<bits/stdc++.h>
using namespace std;
int num[10];
int main(){
	freopen("number.in","r",stdin);	freopen("number.out","w",stdout);
	string s,ans;
	cin>>s;
	for(long int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			num[s[i]-'0']++;
		}
	}
	for(int i=10;i>=0;i--){
		for(;num[i]>0;num[i]--){
			ans+=('0'+i);
		}
	}
	cout<<ans;
	return 0;
}
