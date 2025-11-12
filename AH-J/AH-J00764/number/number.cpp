#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if('0'<=s[i]&&s[i]<='9'){
			cnt[s[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++){
			cout<<i;
		}
	}
	return 0;
}
