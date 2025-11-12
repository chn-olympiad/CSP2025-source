#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll cnt[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int k=0;k<cnt[i];k++){
			printf("%d",i);
		}
	}
	return 0;
}