#include<iostream>
#include<string>
using namespace std;
typedef long long LL;
LL cnt[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(LL i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[s[i]-'0']++;
		}
	}
	for(LL i=9;i>=0;i--){
		for(LL j=1;j<=cnt[i];j++){
			cout<<i;
		}
	}
	return 0;
}
